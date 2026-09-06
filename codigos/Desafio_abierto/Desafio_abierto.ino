#include <ESP32Servo.h>

// ==========================================
// CONFIGURACIÓN DE PINES Y HARDWARE
// ==========================================
const int trigPinIzq = 15; const int echoPinIzq = 2; 
const int trigPinCen = 27; const int echoPinCen = 14; 
const int trigPinDer = 13; const int echoPinDer = 12; 

const int enaPin = 25; const int in1Pin = 33; const int in2Pin = 32; 
const int servoPin = 26; 
Servo direccionServo;

// ==========================================
// CONSTANTES DE DIRECCIÓN Y GIROS
// ==========================================
const int CENTRO_PERFECTO = 95;
const int GIRO_DER_ABIERTO = 55;  
const int GIRO_IZQ_ABIERTO = 145; 

// Fuerza del latigazo de contra-volante para enderezar
const int IMPULSO_COMPENSACION = 35; 

int velocidadCrucero = 175; 
int velocidadGiro = 150; 

// ==========================================
// VARIABLES PID Y ESCUDO (Para la recta)
// ==========================================
float Kp = 0.7;  
float Kd = 1.5;  

int ultimoError = 0;
int refIzq = 0;
int refDer = 0;
int errorInicial = 0;

unsigned long tiempoAnterior = 0;
const int INTERVALO_COMPENSACION = 40; 
const int ESCUDO_LATERAL = 25; 
const int FUERZA_ESCUDO = 30;  

// ==========================================
// INTELIGENCIA DE INTERSECCIONES
// ==========================================
enum SentidoPista { DESCONOCIDO, HORARIO, ANTIHORARIO };
SentidoPista sentido = DESCONOCIDO;

enum EstadoVehiculo { NAV_RECTA, GIRO_ESQUINA, SALIDA_CURVA };
EstadoVehiculo estadoActual = NAV_RECTA;

unsigned long tiempoInicioEstado = 0;
int anguloGiroActual = CENTRO_PERFECTO;

void setup() {
  Serial.begin(115200);

  pinMode(trigPinIzq, OUTPUT); pinMode(echoPinIzq, INPUT);
  pinMode(trigPinCen, OUTPUT); pinMode(echoPinCen, INPUT);
  pinMode(trigPinDer, OUTPUT); pinMode(echoPinDer, INPUT);
  pinMode(enaPin, OUTPUT); pinMode(in1Pin, OUTPUT); pinMode(in2Pin, OUTPUT);

  ESP32PWM::allocateTimer(0);
  direccionServo.setPeriodHertz(50); 
  direccionServo.attach(servoPin, 500, 2400);
  direccionServo.write(CENTRO_PERFECTO); 
  detenerMotores();
  
  Serial.println("TOMA DE FOTOGRAFÍA EN 1.5 SEGUNDOS...");
  delay(1500); 

  refIzq = leerUltrasonicoPromedio(trigPinIzq, echoPinIzq);
  refDer = leerUltrasonicoPromedio(trigPinDer, echoPinDer);
  errorInicial = refIzq - refDer; 
  
  delay(500); 
  arrancarAdelante(velocidadCrucero);
}

void loop() {
  unsigned long tiempoActual = millis();

  int distIzq = leerUltrasonicoPromedio(trigPinIzq, echoPinIzq);
  int distDer = leerUltrasonicoPromedio(trigPinDer, echoPinDer);
  int distCen = leerUltrasonicoPromedio(trigPinCen, echoPinCen);

  switch (estadoActual) {
    
    // ========================================================
    // ESTADO 1: AVANCE EN LÍNEA RECTA
    // ========================================================
    case NAV_RECTA: {
      analogWrite(enaPin, velocidadCrucero);

      bool huecoDer = (distDer > 80);
      bool huecoIzq = (distIzq > 80);

      if (sentido == HORARIO) huecoIzq = false;
      if (sentido == ANTIHORARIO) huecoDer = false;

      // --- DECISIÓN DE GIRO ---
      if (huecoDer) {
        sentido = HORARIO;
        anguloGiroActual = GIRO_DER_ABIERTO;
        estadoActual = GIRO_ESQUINA;
        tiempoInicioEstado = millis();
        break; 
      } 
      else if (huecoIzq) {
        sentido = ANTIHORARIO;
        anguloGiroActual = GIRO_IZQ_ABIERTO;
        estadoActual = GIRO_ESQUINA;
        tiempoInicioEstado = millis();
        break; 
      }
      else if (distCen < 35) {
        anguloGiroActual = (distIzq > distDer) ? GIRO_IZQ_ABIERTO : GIRO_DER_ABIERTO;
        estadoActual = GIRO_ESQUINA;
        tiempoInicioEstado = millis();
        break;
      }

      // --- NAVEGACIÓN PID Y ESCUDO LATERAL ---
      if (tiempoActual - tiempoAnterior >= INTERVALO_COMPENSACION) {
        tiempoAnterior = tiempoActual;

        if (distIzq < ESCUDO_LATERAL) {
          direccionServo.write(CENTRO_PERFECTO - FUERZA_ESCUDO);
          ultimoError = 0;
        } 
        else if (distDer < ESCUDO_LATERAL) {
          direccionServo.write(CENTRO_PERFECTO + FUERZA_ESCUDO);
          ultimoError = 0;
        }
        else {
          int diferenciaActual = distIzq - distDer;
          int errorPID = diferenciaActual - errorInicial;

          if (abs(errorPID) <= 5) errorPID = 0;

          float pTerm = Kp * errorPID;
          float dTerm = Kd * (errorPID - ultimoError);
          ultimoError = errorPID;

          int correccion = (int)(pTerm + dTerm);
          correccion = constrain(correccion, -18, 18); 
          direccionServo.write(CENTRO_PERFECTO + correccion);
        }
      }
      break;
    }

    // ========================================================
    // ESTADO 2: GIRANDO (COORDINACIÓN DE SENSORES)
    // ========================================================
    case GIRO_ESQUINA: {
      direccionServo.write(anguloGiroActual); 
      analogWrite(enaPin, velocidadGiro); 
      
      if (millis() - tiempoInicioEstado > 200) {
        if (anguloGiroActual == GIRO_IZQ_ABIERTO) {
          if (distCen > 85 && distDer < 40) {
            estadoActual = SALIDA_CURVA;
            tiempoInicioEstado = millis();
          }
        }
        else if (anguloGiroActual == GIRO_DER_ABIERTO) {
          if (distCen > 70 && distIzq < 60) {
            estadoActual = SALIDA_CURVA;
            tiempoInicioEstado = millis();
          }
        }
      }
      break;
    }

    // ========================================================
    // ESTADO 3: SALIDA DE CURVA CON IMPULSO DE CONTRA-VOLANTE
    // ========================================================
    case SALIDA_CURVA: {
      unsigned long tiempoEnSalida = millis() - tiempoInicioEstado;
      analogWrite(enaPin, velocidadCrucero);
      
      if (tiempoEnSalida < 150) {
        // FASE 1: Latigazo contrario para matar la inercia (0ms a 150ms)
        if (anguloGiroActual == GIRO_IZQ_ABIERTO) {
          direccionServo.write(CENTRO_PERFECTO - IMPULSO_COMPENSACION); // Tuerce derecha
        } else {
          direccionServo.write(CENTRO_PERFECTO + IMPULSO_COMPENSACION); // Tuerce izquierda
        }
      } 
      else if (tiempoEnSalida < 300) {
        // FASE 2: Estabiliza en el centro perfecto (150ms a 300ms)
        direccionServo.write(CENTRO_PERFECTO);
      } 
      else {
        // FASE 3: Entrega el control limpio al PID
        estadoActual = NAV_RECTA;
        ultimoError = 0; 
        tiempoAnterior = millis();
      }
      break;
    }
  }
}

// ==========================================
// FUNCIÓN ROBUSTA: OVERSAMPLING + TECHO 300cm
// ==========================================
int leerUltrasonicoPromedio(int trig, int echo) {
  int suma = 0;
  int lecturasValidas = 0;

  for (int i = 0; i < 3; i++) {
    digitalWrite(trig, LOW); delayMicroseconds(2);
    digitalWrite(trig, HIGH); delayMicroseconds(10);
    digitalWrite(trig, LOW);

    unsigned long duracion = pulseIn(echo, HIGH, 18000); 
    
    if (duracion > 0) {
      int distancia = duracion * 0.034 / 2;
      if (distancia <= 300) {
        suma += distancia;
        lecturasValidas++;
      }
    }
    delay(2); 
  }

  if (lecturasValidas == 0) return 300; 
  return suma / lecturasValidas;
}

void arrancarAdelante(int vel) {
  digitalWrite(in1Pin, HIGH); digitalWrite(in2Pin, LOW);
  analogWrite(enaPin, vel);
}

void detenerMotores() {
  digitalWrite(in1Pin, LOW); digitalWrite(in2Pin, LOW);
  analogWrite(enaPin, 0);
}
