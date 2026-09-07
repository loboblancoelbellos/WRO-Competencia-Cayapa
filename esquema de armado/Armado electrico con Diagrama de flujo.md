## **Diagrama Electrico**


<img width="624" height="583" alt="DIAGRAMA DINOCO" src="https://github.com/user-attachments/assets/0b882cfa-aef1-483a-92a9-4b54f77824ca" />


## Diagrama de Flujo del Circuito : este documento presenta un diagrama de flujo que ilustra la lógica operativa de un circuito, basado en la imagen de referencia proporcionada.




Este apartado detalla la secuencia operativa del circuito integrado del vehículo autónomo, reflejando la transición hacia el procesamiento avanzado del ESP32 y el control PID.

### Explicación Detallada del Flujo:

* **Inicio y Encendido (Gestión de Energía):** Representa el punto de partida. El sistema se alimenta de un paquete de 3 baterías 18650 (11.1V). La energía se distribuye a través de dos interruptores: uno dirige el voltaje crudo al **Puente H L298N** para máxima tracción, y el otro hacia el regulador de voltaje LM2596.
* **Acondicionamiento de Voltaje (Buck Converter):** El módulo LM2596 reduce y estabiliza los 11.1V a un bus seguro de 5V para alimentar los sensores, el servomotor y la placa de expansión.
* **Inicialización del Microcontrolador (ESP32):** El procesador arranca y configura sus pines GPIO. Como opera con lógica de 3.3V, se establece la comunicación segura con los sensores (que operan a 5V) a través del conversor de nivel lógico bidireccional.
* **Inicialización de Periféricos:** Los sensores ultrasónicos HC-SR04 se preparan para emitir pulsos. El servomotor MG90S se calibra en su punto muerto central (dirección recta) y se establecen los pines de control (PWM, IN1, IN2) que comunicarán al ESP32 con el Puente H.
* **Bucle Principal (Control de Navegación):** El programa entra en un ciclo de ejecución continuo, vital para la autonomía del vehículo.
* **Lectura y Filtrado de Sensores:** Se consultan los sensores frontal y laterales. Se aplica un filtro de media móvil por software para descartar picos de ruido acústico o lecturas falsas.
* **Evaluación de Entorno (Algoritmo PID y Tracción):** 
  * **Control de Velocidad:** Si el sensor frontal detecta una pared cercana, el ESP32 calcula una reducción de velocidad y envía la señal PWM al **Puente H L298N**. El L298N amplifica esta señal y regula el giro del **Motor DC** para frenar o maniobrar con seguridad. Si la vía está libre, se envía la señal para mantener la velocidad de crucero.
  * **Cálculo de Error:** En paralelo, el ESP32 calcula la diferencia de distancias laterales para determinar la desviación del centro del carril ($Error = Distancia Izquierda - Distancia Derecha$).
  * **Corrección de Trayectoria:** La salida del algoritmo PID ajusta dinámicamente el ángulo del servomotor (geometría Ackermann) para recentrar el vehículo.
* **Retorno del Bucle:** El sistema regresa inmediatamente al paso de lectura de sensores, garantizando una alta frecuencia de muestreo y correcciones en tiempo real.

### 📊 Representación Visual

```mermaid
graph TD
    A[Inicio: Encendido Baterías 18650] --> B{Interruptores}
    
    B -->|Switch 1| C[Puente H L298N recibe 11.1V directos]
    B -->|Switch 2| D[Regulador LM2596 reduce a 5V]
    
    D --> E[ESP32 arranca a 3.3V]
    E --> F[Inicializar Periféricos: Sensores y Servo]
    
    F --> G((Bucle Principal))
    
    G --> H[ESP32: Leer y Filtrar Sensores Ultrasónicos]
    H --> I{¿Pared frontal cercana?}
    
    I -->|Sí| J[ESP32: Envía señal PWM baja / Freno]
    I -->|No| K[ESP32: Envía señal PWM alta / Crucero]
    
    J --> L[Puente H L298N]
    K --> L
    
    L --> M[Motor DC: Ajusta tracción trasera]
    
    M --> N[ESP32: Cálculo de Error PID lateral]
    N --> O[ESP32: Ajustar Ángulo Servomotor MG90S]
    
    O --> G
```
