// ==========================================
// CONFIGURACIÓN DE PINES (Mapeo Acordado)
// ==========================================
// Sensor Ultrasónico Izquierdo
const int trigIzq = 15;
const int echoIzq = 2;

// Sensor Ultrasónico Central (Delantero)
const int trigCentral = 27;
const int echoCentral = 5;

// Sensor Ultrasónico Derecho
const int trigDer = 13;
const int echoDer = 12;

void setup() {
  // Inicializar monitor serie a alta velocidad
  Serial.begin(115200);
  Serial.println("\n--- TELEMETRÍA DE ULTRASONIDOS INICIADA ---");

  // Configuración de pines lógicos
  pinMode(trigIzq, OUTPUT);
  pinMode(echoIzq, INPUT);

  pinMode(trigCentral, OUTPUT);
  pinMode(echoCentral, INPUT);

  pinMode(trigDer, OUTPUT);
  pinMode(echoDer, INPUT);

  Serial.println("Coloca un obstáculo frente a los sensores para probar...");
  delay(1000);
}

void loop() {
  // Captura secuencial de distancias (evita eco cruzado)
  long distanciaIzq     = medirDistancia(trigIzq, echoIzq);
  delay(10); // Pequeña pausa para que el sonido se disipe en el entorno
  
  long distanciaCentral = medirDistancia(trigCentral, echoCentral);
  delay(10);
  
  long distanciaDer     = medirDistancia(trigDer, echoDer);

  // Mostrar lecturas en el Monitor Serie en una sola línea scannable
  Serial.print("[DISTANCIAS] ");
  Serial.print("IZQ: ");   Serial.print(distanciaIzq);     Serial.print(" cm | ");
  Serial.print("CEN: ");   Serial.print(distanciaCentral); Serial.print(" cm | ");
  Serial.print("DER: ");   Serial.print(distanciaDer);     Serial.println(" cm");

  delay(300); // Frecuencia de actualización de pantalla cómoda
}

// ==========================================
// FUNCIÓN ESTÁNDAR DE LECTURA HC-SR04
// ==========================================
long medirDistancia(int pinTrig, int pinEcho) {
  // Asegurar pulso limpio
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  
  // Generar el disparo de 10 microsegundos
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  // Medir el tiempo de retorno del pulso (Timeout de 30ms = ~5 metros max)
  long duracion = pulseIn(pinEcho, HIGH, 30000);
  
  // Calcular la distancia en centímetros basándose en la velocidad del sonido
  long distancia = duracion * 0.034 / 2;
  
  // Si da 0, significa fuera de rango o error de eco
  if (distancia == 0) {
    return 999; 
  }
  return distancia;
}
