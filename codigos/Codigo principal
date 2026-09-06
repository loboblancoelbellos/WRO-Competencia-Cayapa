#include <ESP32Servo.h>

// ==========================================
// PINES DE HARDWARE (Basado en tu diagrama)
// ==========================================
const int trigPinIzq = 15; const int echoPinIzq = 2; 
const int trigPinCen = 27; const int echoPinCen = 14; 
const int trigPinDer = 13; const int echoPinDer = 12; 

const int enaPin = 25; const int in1Pin = 33; const int in2Pin = 32; 
const int servoPin = 26; 

Servo direccionServo;

void setup() {
  Serial.begin(115200);
  Serial.println("\n--- INICIANDO TEST GENERAL DE HARDWARE ---");

  // Configurar Pines
  pinMode(trigPinIzq, OUTPUT); pinMode(echoPinIzq, INPUT);
  pinMode(trigPinCen, OUTPUT); pinMode(echoPinCen, INPUT);
  pinMode(trigPinDer, OUTPUT); pinMode(echoPinDer, INPUT);
  pinMode(enaPin, OUTPUT); pinMode(in1Pin, OUTPUT); pinMode(in2Pin, OUTPUT);
  detenerMotores();

  // Inicializar Servo
  ESP32PWM::allocateTimer(0);
  direccionServo.setPeriodHertz(50); 
  direccionServo.attach(servoPin, 500, 2400);
  delay(2000); // Dar tiempo a que enciendas la batería

  // ----------------------------------------------------
  // PRUEBA 1: DIRECCIÓN (SERVO)
  // ----------------------------------------------------
  Serial.println("PRUEBA 1: Servo a la DERECHA...");
  direccionServo.write(55);
  delay(1000);
  Serial.println("PRUEBA 1: Servo a la IZQUIERDA...");
  direccionServo.write(145);
  delay(1000);
  Serial.println("PRUEBA 1: Servo al CENTRO...");
  direccionServo.write(95);
  delay(1500);

  // ----------------------------------------------------
  // PRUEBA 2: TRACCIÓN (MOTOR DC)
  // ----------------------------------------------------
  Serial.println("PRUEBA 2: Motor hacia ADELANTE...");
  digitalWrite(in1Pin, HIGH); digitalWrite(in2Pin, LOW);
  analogWrite(enaPin, 150);
  delay(1500);
  
  detenerMotores();
  delay(500);

  Serial.println("PRUEBA 2: Motor hacia ATRAS...");
  digitalWrite(in1Pin, LOW); digitalWrite(in2Pin, HIGH);
  analogWrite(enaPin, 150);
  delay(1500);

  detenerMotores();
  Serial.println("PRUEBA 2: Fin de prueba de motores.");
  delay(1000);

  Serial.println("\nPRUEBA 3: LECTURA DE SENSORES ULTRASÓNICOS");
  Serial.println("Pasa la mano frente a los sensores. Presiona el botón de reinicio (EN) en el ESP32 para repetir todo.");
  Serial.println("--------------------------------------------------");
}

void loop() {
  // ----------------------------------------------------
  // PRUEBA 3: CICLO INFINITO LEYENDO SENSORES
  // ----------------------------------------------------
  int distIzq = leerDistancia(trigPinIzq, echoPinIzq);
  int distCen = leerDistancia(trigPinCen, echoPinCen);
  int distDer = leerDistancia(trigPinDer, echoPinDer);

  Serial.print("IZQ: "); Serial.print(distIzq); Serial.print(" cm \t|\t");
  Serial.print("CEN: "); Serial.print(distCen); Serial.print(" cm \t|\t");
  Serial.print("DER: "); Serial.print(distDer); Serial.println(" cm");

  delay(300); // Esperar un poco para no inundar el monitor
}

// Función auxiliar para leer los sensores sin bloquear el código
int leerDistancia(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Timeout de 18000 microsegundos (~300 cm máximo) para evitar que el ESP32 se cuelgue si un cable se desconecta
  long duracion = pulseIn(echo, HIGH, 18000); 
  
  if (duracion == 0) return 300; // Si no hay eco, devuelve 300cm
  return duracion * 0.034 / 2;
}

void detenerMotores() {
  digitalWrite(in1Pin, LOW); digitalWrite(in2Pin, LOW);
  analogWrite(enaPin, 0);
}
