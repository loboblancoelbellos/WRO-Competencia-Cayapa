// Pines del Puente H extraídos deL código principal
const int enaPin = 25; 
const int in1Pin = 33; 
const int in2Pin = 32; 

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando prueba de motor y Puente H...");

  // Configurar pines como salida
  pinMode(enaPin, OUTPUT); 
  pinMode(in1Pin, OUTPUT); 
  pinMode(in2Pin, OUTPUT);
}

void loop() {
  Serial.println("Adelante...");
  digitalWrite(in1Pin, HIGH); 
  digitalWrite(in2Pin, LOW);
  analogWrite(enaPin, 150); // Velocidad moderada (0-255)
  delay(2000);

  Serial.println("Detenido...");
  digitalWrite(in1Pin, LOW); 
  digitalWrite(in2Pin, LOW);
  analogWrite(enaPin, 0);
  delay(1000);

  Serial.println("Atrás...");
  digitalWrite(in1Pin, LOW); 
  digitalWrite(in2Pin, HIGH);
  analogWrite(enaPin, 150);
  delay(2000);

  Serial.println("Detenido...");
  digitalWrite(in1Pin, LOW); 
  digitalWrite(in2Pin, LOW);
  analogWrite(enaPin, 0);
  delay(2000);
}
