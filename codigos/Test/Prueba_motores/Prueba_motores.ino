// Pines de control del Puente H para el motor de tracción
const int enaPin = 25; // Pin PWM para controlar la velocidad
const int in1Pin = 33; // Pin de dirección 1
const int in2Pin = 32; // Pin de dirección 2

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando test de VELOCIDADES del motor...");

  pinMode(enaPin, OUTPUT); 
  pinMode(in1Pin, OUTPUT); 
  pinMode(in2Pin, OUTPUT);
  
  // Asegurarnos de que arranque apagado
  digitalWrite(in1Pin, LOW); 
  digitalWrite(in2Pin, LOW);
  analogWrite(enaPin, 0);
  delay(2000); // Tiempo para encender la batería
}

void loop() {
  // ==========================================
  // CICLO HACIA ADELANTE
  // ==========================================
  digitalWrite(in1Pin, HIGH); 
  digitalWrite(in2Pin, LOW);

  Serial.println("Adelante -> Velocidad BAJA (PWM: 100)");
  analogWrite(enaPin, 100);
  delay(2500);

  Serial.println("Adelante -> Velocidad MEDIA (PWM: 175)");
  analogWrite(enaPin, 175);
  delay(2500);

  Serial.println("Adelante -> Velocidad MÁXIMA (PWM: 255)");
  analogWrite(enaPin, 255);
  delay(2500);

  // Frenado entre cambios de dirección
  Serial.println("Frenando...");
  analogWrite(enaPin, 0);
  delay(1500);

  // ==========================================
  // CICLO HACIA ATRÁS
  // ==========================================
  digitalWrite(in1Pin, LOW); 
  digitalWrite(in2Pin, HIGH);

  Serial.println("Atrás -> Velocidad BAJA (PWM: 100)");
  analogWrite(enaPin, 100);
  delay(2500);

  Serial.println("Atrás -> Velocidad MEDIA (PWM: 175)");
  analogWrite(enaPin, 175);
  delay(2500);

  Serial.println("Atrás -> Velocidad MÁXIMA (PWM: 255)");
  analogWrite(enaPin, 255);
  delay(2500);

  // Pausa larga antes de repetir todo el ciclo
  Serial.println("Ciclo terminado. Pausa de 3 segundos...");
  analogWrite(enaPin, 0);
  delay(3000);
}
