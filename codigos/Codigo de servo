#include <ESP32Servo.h>

Servo direccionServo;  
const int servoPin = 26; 

int anguloActual = 90; 

void setup() {
  Serial.begin(115200);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  direccionServo.setPeriodHertz(50); 
  
  direccionServo.attach(servoPin, 500, 2400); 

  // REGLA 1: Siempre centrar las ruedas exactamente a 90° al iniciar
  direccionServo.write(anguloActual);
  Serial.println("INICIO: Ruedas centradas. Esperando 2 segundos...");
  delay(2000);
}

void loop() {
  // 1. Giro hacia la Izquierda
  Serial.println("Girando Izquierda (50°)");
  girarSuave(50, 2); 
  delay(1000);

  // 2. Retorno al Centro
  Serial.println("Retorno al Centro (90°)");
  girarSuave(90, 2);
  delay(1000);

  // 3. Giro hacia la Derecha
  Serial.println("Girando Derecha (130°)");
  girarSuave(130, 2);
  delay(1000);

  // 4. Retorno al Centro
  Serial.println("Retorno al Centro (90°)");
  girarSuave(90, 2);
  delay(2000); // Pausa un poco más larga antes de repetir la secuencia entera
}

// =========================================================================
// Función optimizada para giros rápidos pero controlados
// =========================================================================
void girarSuave(int anguloObjetivo, int velocidadDelay) {
  
  while (anguloActual != anguloObjetivo) {
    
    if (anguloActual < anguloObjetivo) {
      anguloActual += 4; // Avanza de 2 en 2 grados
      // Seguro contra sobrepaso
      if (anguloActual > anguloObjetivo) anguloActual = anguloObjetivo; 
    } else {
      anguloActual -= 4; 
      if (anguloActual < anguloObjetivo) anguloActual = anguloObjetivo;
    }
    
    direccionServo.write(anguloActual); 
    delay(velocidadDelay); 
  }
}
