## **Diagrama Electrico**


<img width="624" height="583" alt="DIAGRAMA DINOCO" src="https://github.com/user-attachments/assets/0b882cfa-aef1-483a-92a9-4b54f77824ca" />


## Diagrama de Flujo del CircuitoEste documento presenta un diagrama de flujo que ilustra la lógica operativa de un circuito, basado en la imagen de referencia proporcionada.

graph TD
    %% Inicialización y Switches
    Inicio([Conexión de 3 Baterías]) --> SW1{¿Switch 1 Cerrado?}
    SW1 -- Sí --> P1[Energiza Puente H L298N]
    SW1 -- Sí --> P2[Energiza Convertidor Regulador]
    
    P2 --> SW2{¿Switch 2 Cerrado?}
    SW2 -- Sí --> P3[Energiza ESP32]
    SW2 -- Sí --> P4[Energiza Servomotor]
    SW2 -- Sí --> P5[Energiza Convertidor de Nivel Lógico]
    
    P5 --> P6[Alimenta Sensores Ultrasónicos 3.3V]
    
    P3 --> S1[ESP32: Configura Pines]
    P4 --> S1
    P6 --> S1
    
    S1 --> S2[Servo al centro 95° y Motor detenido]
    S2 --> S3[Pausa de 1.5s Toma de Fotografía]
    S3 --> S4[Lectura lateral inicial: Establece errorInicial]
    S4 --> S5[Arranca Motor DC a velocidadCrucero]
    
    %% Bucle Principal
    S5 --> Bucle((Inicio del Loop))
    Bucle --> L1[Lectura promediada de 3 Sensores]
    L1 --> Estado{¿Estado Actual?}
    
    %% ESTADO: NAV_RECTA
    Estado -- NAV_RECTA --> N1{¿Hueco lateral > 80cm <br>o Frente < 35cm?}
    N1 -- Sí --> N2[Define sentido y cambia a GIRO_ESQUINA]
    N1 -- No --> N3{¿Dist. lateral < 25cm?}
    
    N3 -- Sí --> N4[ESCUDO LATERAL: Giro brusco evasivo]
    N3 -- No --> N5[PID: Microajuste de dirección servo]
    
    N4 --> Bucle
    N5 --> Bucle
    N2 --> Bucle
    
    %% ESTADO: GIRO_ESQUINA
    Estado -- GIRO_ESQUINA --> G1[Servo al ángulo máximo]
    G1 --> G2[Motor baja a velocidadGiro]
    G2 --> G3{¿Frente despejado y <br> pared lateral detectada?}
    G3 -- No --> Bucle
    G3 -- Sí --> G4[Cambia a SALIDA_CURVA]
    G4 --> Bucle
    
    %% ESTADO: SALIDA_CURVA
    Estado -- SALIDA_CURVA --> C1[Motor sube a velocidadCrucero]
    C1 --> C2{¿Tiempo transcurrido?}
    
    C2 -- 0 a 150ms --> C3[FASE 1: Latigazo contra-volante]
    C2 -- 150 a 300ms --> C4[FASE 2: Estabiliza servo al centro 95°]
    C2 -- Más de 300ms --> C5[FASE 3: Limpia PID y cambia a NAV_RECTA]
    
    C3 --> Bucle
    C4 --> Bucle
    C5 --> Bucle.md


**Explicación Detallada del Diagrama de Flujo**:El diagrama de flujo desglosa los pasos inferidos del funcionamiento del circuito:Inicio:Representa el punto de partida para la secuencia de operaciones del circuito.

**ENCENDIDO**:Se refiere al momento en que el circuito recibe energía. Basado en la imagen original, esto se logra a través de las baterías de iones de litio (18650 Li-ion).Verificar Voltaje de Batería:Aunque no se visualiza un componente específico para esta tarea en el circuito, se asume como una buena práctica. La lógica aquí es asegurar que la fuente de energía sea adecuada para el funcionamiento continuo.Voltaje OK: Si el nivel de voltaje es suficiente, el sistema procede a inicializar el microcontrolador.Voltaje Bajo: Si el voltaje es crítico, el sistema podría emitir una advertencia visual o sonora, o incluso apagarse para proteger los componentes y prolongar la vida útil de las baterías.

**Inicializar Arduino UNO**:El corazón del circuito, el microcontrolador Arduino UNO, comienza su secuencia de arranque. Esto incluye la configuración de sus puertos (pines de entrada/salida) y la preparación para la ejecución del código.Inicializar Sensores Ultrasónicos Los tres sensores HC-SR04 se configuran para su función principal: emitir pulsos de sonido y medir el tiempo que tardan en regresar para calcular distancias.Inicializar Servo Motor El servo motor se establece en una posición predeterminada, que generalmente es su punto central o una posición de reposo inicial. Inicializar Controlador de Motor El módulo controlador de motor L298N se prepara para recibir señales del Arduino y controlar el motor de corriente continua (DC).

**Iniciar Bucle Principal**:El programa del Arduino entra en un ciclo de ejecución continuo. Este bucle es crucial, ya que permite que el circuito opere de forma autónoma y reactiva.Leer Distancia del Sensor 1, 2, 3:Dentro del bucle principal, cada sensor ultrasónico realiza una lectura de distancia. Estas lecturas son fundamentales para la detección de objetos.Obstáculo Detectado?

Este es un punto de decisión crítico. El sistema procesa las lecturas de los sensores para determinar si hay algún objeto dentro de un rango de proximidad que requiera una acción.Sí Si se identifica un obstáculo Mover Servo Motor El servo motor ajusta su posición. Esto podría ser para reorientar un sensor, activar una parte móvil o iniciar una acción de evasión.Controlar Motor DC a Través del Controlador: El motor DC se activa o se le da una instrucción (por ejemplo, avanzar, detenerse, retroceder, girar) para reaccionar al obstáculo.Esperar / Retrasar: Una breve pausa permite que las acciones iniciadas se completen o para estabilizar el sistema antes de la siguiente iteración de lectura.No: Si no se detectan obstáculos, el sistema simplemente continúa su proceso de monitoreo.Bucle Independientemente del resultado de la detección de obstáculos, el flujo regresa al paso de lectura de distancias. Esto asegura un monitoreo constante del entorno y una capacidad de respuesta en tiempo real del circuito.
