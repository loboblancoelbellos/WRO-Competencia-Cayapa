
# 🚀 WRO 2026 Future Engineers: Equipo Cayapa - Robot "Dinoco"

<img width="800" height="1080" alt="equipo cayapa2026-09-06 at 17 40 40" src="https://github.com/user-attachments/assets/5f3ed0f4-17f1-4fa6-af08-a1def53fc793" />

> *Vehículo autónomo de diseño compacto desarrollado por el equipo **Cayapa** para competir en la categoría Future Engineers de la World Robot Olympiad (WRO) 2026. Diseñado para optimizar el radio de giro, la estabilidad estructural y la velocidad de procesamiento mediante un microcontrolador ESP32 y una matriz de sensores ultrasónicos.*

---

## 📌 ÍNDICE
1. Introducción y Datos del Equipo
2. Evolución e Iteraciones del Diseño Mecánico
3. Movilidad y Sistema de Tracción/Dirección
4. Arquitectura de Hardware, Sensores y Energía
5. Dimensiones de la Pista y Estrategia de Control
6. Análisis de Fallas, Riesgos y Lecciones Aprendidas
7. Guía de Reproducibilidad y Archivos del Repositorio

---

## 👥 1. Introducción y Datos del Equipo

Este repositorio documenta el desarrollo integral de nuestro vehículo autónomo **"Dinoco"**. Como estudiantes de Ingeniería en Electrónica, aplicamos principios de control automático, diseño mecánico e integración de sistemas electromecánicos para cumplir con la normativa oficial de la WRO 2026.

### Miembros del Equipo

* **Dharma Alexandra Peña jimenez** - *Tutora encargada del Equipo*
-
* **Leontino Jose Medina Di Donato** - *Diseño Mecánico, Modelado e Impresión 3D*
* **Adriana Carolina Palmar Molero** - *Diseño de Circuitos, Sistema de Potencia y Cableado*
* **Nilecto Noe Leon Guerere** - *Desarrollo de Software y Algoritmos de Control*

---

## 🔄 2. Evolución e Interaciones del Diseño Mecánico

El desarrollo de *Dinoco* ha sido un proceso estrictamente iterativo, donde cada modificación respondió a fallas diagnosticadas durante pruebas dinámicas en pista.

### 2.1. Prototipo 1.0: Chasis RC Modificado y Arquitectura Basada en Arduino Mega

**Motivación y Selección Mecánica Inicial (Ciclo 2025)**

Debido a las restricciones de tiempo en la fase inicial del proyecto para las competencias de 2025, el equipo optó por no diseñar un chasis desde cero. En su lugar, se seleccionó como plataforma de pruebas un chasis comercial de radiocontrol (RC) de dimensiones iniciales de 45 cm de largo por 20 cm de ancho. Para adecuarlo al reglamento de esa temporada, se redujo la longitud recortando la estructura central.

Sistema de Tracción: Transmisión por eje posterior rígido hacia ambas ruedas traseras.

Sistema de Dirección: Servomotor MG995, seleccionado por su elevado par de apriete (torque).

**Diagnóstico Crítico de Fallas (¿Por qué se descartó el Prototipo 2025 para el diseño actual?)**

Evaluar el rendimiento de este primer prototipo fue fundamental para sentar las bases mecánicas y electrónicas del modelo que competirá este año. Las principales deficiencias documentadas fueron:

Radio de Giro Ineficiente: Con dimensiones cercanas al límite máximo, el vehículo requería un radio de viraje sumamente amplio, siendo incapaz de completar curvas de 90° cerradas o ejecutar el estacionamiento autónomo.

Ruido Inductivo (Back-EMF): El servomotor MG995 inyectaba picos de corriente hacia el pin de señal del Arduino Mega, provocando bloqueos aleatorios del programa.

Sobrecarga Térmica y Caídas de Tensión (Brownouts): El regulador LM7805 sufría sobrecalentamiento por la demanda simultánea de los sensores y el servo, ocasionando lecturas erráticas y reinicios constantes.

---

### 2.2. Dinoco (Versión 2.0 / Actual): Optimización Dimensional y Upgrade Electrónico

Tras analizar las limitaciones mecánicas y eléctricas del Prototipo 1.0, rediseñamos la plataforma desde cero para crear **Dinoco 2.0**, enfocándonos en la ergonomía, la velocidad de procesamiento y la modularidad.

**Vista del Chasis Actual:**
-
<img width="1280" height="720" alt="carrito 2026-09-06 at 17 45 28" src="https://github.com/user-attachments/assets/17bf026b-2edc-4e55-b8d5-af26b3677a9d" />

---
**Ensamblaje de Componentes:**


<img width="700" height="900" alt="adriana ensamblando 2026-09-06 at 17 45 37" src="https://github.com/user-attachments/assets/1cf71c6b-20a4-48c0-9acb-80939633c7cf" />

---

<img width="700" height="900" alt="leontino ensamblando 2026-09-06 at 17 44 20" src="https://github.com/user-attachments/assets/960e2898-cf7f-4d44-b53a-16cfc8f6e16f" />

---

* **Reducción Ergonométrica:** La longitud pasó de 45 cm a un tamaño compacto entre **23 cm y 25 cm**, y el ancho se optimizó a **15 cm**. Esta disminución drástica del volumen mejora significativamente la maniobrabilidad del robot dentro de los carriles de la pista.
* **Dirección Simplificada con Rodamientos:** Se rediseñó el tren delantero integrando **rodamientos (rolineras)** en las manguetas de dirección. Esto reduce drásticamente la fricción mecánica y elimina el juego holgado.
* **Migración al ESP32 + Shield Expansor:** Reemplazamos el Arduino Mega por un **ESP32** montado sobre una placa de expansión de pines, aprovechando su arquitectura Dual-Core a 240 MHz para el procesamiento del algoritmo PID.

---

## ⚙️ 3. Movilidad y Sistema de Tracción/Dirección

### 3.1. Tracción Trasera: Motor DC Makeblock 9V (185 RPM)
![Motor Makeblock](https://github.com/user-attachments/assets/8a9cdd8b-57d4-416b-b355-9b4c4810f2ba)

* **Justificación de Selección:** Proporciona un **alto par motor (torque)** gracias a su caja reductora metálica, manteniendo constante la tracción de las ruedas traseras.
* **Control de Velocidad:** Gobernado a través de señales PWM mediante el controlador Puente H L298N.

### 3.2. Dirección delantera tipo Ackermann con Rodamientos
![Servo MG90S](https://github.com/user-attachments/assets/8a5d8723-35ca-40f7-a34a-3fabfd5f0480)

* **Mecanismo:** Geometría Ackermann equipada con **rodamientos (rolineras)** en los puntos de pivote para minimizar el rozamiento.
* **Actuador:** Servomotor **MG90S con engranajes metálicos**, evitando desgastes por colisión y garantizando un ángulo de giro suave y rápido.

---

## 🔌 4. Arquitectura de Hardware, Sensores y Energía

Para el diseño de **Dinoco 2.0**, realizamos una reestructuración completa de los componentes electrónicos y electromecánicos, basándonos en un análisis de compensaciones (*Trade-offs*).

### 4.1. Unidad de Procesamiento Central (Cerebro)

**ESP32 (Placa de Desarrollo 30 Pines)**

![ESP32](https://github.com/user-attachments/assets/acf25497-c3d1-482c-a017-23cde340d36b)

* **Función y Ubicación:** Es el cerebro del robot, encargado de ejecutar el control PID y procesar los sensores. Va ubicado en la parte superior del chasis para evitar interferencias.
* **Por qué se cambió:** Reemplaza al Arduino Mega del Prototipo 1.0 (lento y grande). El ESP32 nos da procesamiento Dual-Core a 240 MHz.
* **Ventajas:** Alta velocidad de reloj, conectividad inalámbrica para futura telemetría y tamaño sumamente compacto.
* **Desventajas:** Opera con lógica de 3.3V (a diferencia de los 5V del Arduino), lo que nos obligó a rediseñar la electrónica de sensores para evitar quemar sus pines.

**Shield Expansor para ESP32 (30 Pines)**

![enter image description here](https://megatronica.cc/wp-content/uploads/2025/03/Placa-de-extension-ESP32-30-pines_bornera-MEGATRONICA-Tienda-de-componentes-electronicos-Quito.webp)

* **Función y Ubicación:** Base donde se acopla el ESP32, expandiendo sus pines GPIO a borneras y conectores macho.
* **Por qué se implementó:** En el carro anterior, las conexiones directas o en protoboard generaban falsos contactos con las vibraciones.
* **Ventajas:** Facilita el cableado con terminales Dupont, organiza la distribución de energía y permite sustituir el ESP32 en segundos en caso de falla en los pits.
* **Desventajas:** Aumenta ligeramente la altura de la electrónica principal.

### 4.2. Adaptación y Regulación de Energía

**Conversor de Nivel Lógico (Level Shifter Bidireccional)**

![enter image description here](https://digizone.com.ve/wp-content/uploads/2021/07/conversor-de-nivel-logico-i2c.jpg)

* **Función y Ubicación:** Interfaz colocada entre los sensores ultrasónicos y el ESP32.
* **Por qué se implementó:** El ESP32 solo soporta 3.3V en sus entradas, pero el pin Echo de los sensores ultrasónicos envía pulsos de 5V. 
* **Ventajas:** Protege los pines GPIO del microcontrolador de sobretensiones irreversibles, traduciendo de 5V a 3.3V de forma segura.
* **Desventajas:** Añade complejidad al cableado del esquemático y requiere ser alimentado con ambos voltajes simultáneamente.

**Regulador de Voltaje LM2596 (Buck Converter / Step-Down)**

![enter image description here](https://sumador.com/cdn/shop/products/Lm2596_Electronilab_1_2048x2048.jpg?v=1549320563)

* **Función y Ubicación:** Reduce el voltaje de las baterías (11.1V) a un bus estable y seguro de 5V para la lógica y sensores.
* **Por qué se cambió:** Reemplaza al regulador lineal LM7805 del Prototipo 1.0 que se sobrecalentaba y apagaba el robot.
* **Ventajas:** Al ser un regulador conmutado, tiene una eficiencia de hasta 92%, no se sobrecalienta fácilmente y permite ajustar el voltaje.
* **Desventajas:** Puede introducir un leve ruido de conmutación de alta frecuencia en la línea de alimentación.

**Baterías 18650 (x3) y Portabaterías (Holder)**
![Baterías 18650](https://http2.mlstatic.com/D_NQ_NP_881915-MLV71037692218_082023-O.webp)

* **Función y Ubicación:** Fuente de energía principal. Alojadas en la parte inferior trasera del chasis para mantener el centro de gravedad bajo.
* **Por qué se eligieron:** Proveen **11.1V nominales**. Su alta capacidad de descarga soporta los picos de arranque del motor trasero sin causar reinicios en el procesador.
* **Ventajas:** Recargables, altísima densidad energética y mantienen un voltaje estable por más tiempo.
* **Desventajas:** Requieren un cargador especializado y balanceo de celdas; un cortocircuito puede ser peligroso.

### 4.3. Actuadores y Mecánica de Tracción

**Motor DC Makeblock 9V (185 RPM) y Puente H L298N**
![Motor y L298N](https://github.com/user-attachments/assets/c998e194-728f-4ca4-acd2-dbf268346189)

* **Función y Ubicación:** El motor provee la tracción en el eje trasero sólido. El driver L298N controla su sentido de giro y velocidad mediante PWM.
* **Por qué se conservaron:** Fueron las únicas piezas reutilizadas del Prototipo 1.0. Desarrollar un diferencial desde cero exigía un tiempo del que no disponíamos.
* **Ventajas:** La caja reductora ofrece excelente torque. El driver L298N es robusto, tiene disipador térmico y aísla el ruido del motor.
* **Desventajas:** El eje rígido obliga a un ligero arrastre de las ruedas traseras en curvas cerradas.

**Servomotor MG90S**
![Servo MG90S](https://github.com/user-attachments/assets/8a5d8723-35ca-40f7-a34a-3fabfd5f0480)

* **Función y Ubicación:** Controla la geometría de dirección Ackermann en el tren delantero.
* **Por qué se cambió:** Reemplaza al MG995 (que generaba rebote eléctrico - Back-EMF).
* **Ventajas:** Formato miniatura que ahorra espacio, pero con **engranajes metálicos (Metal Gear)** que garantizan durabilidad frente a golpes.
* **Desventajas:** Menor torque bruto en comparación con el MG995, pero se compensó aliviando la mecánica de la dirección.

**Rodamientos (Rolineras) 608 y 687ZZ**

![enter image description here](https://http2.mlstatic.com/D_NQ_NP_947416-MLV106902264108_022026-O.webp)

![enter image description here](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTfsXJGs0ADARVllLnBRAYkDqMZGpto9uicrkkIOkDcXw&s=10)
* **Función y Ubicación:** Instalados en los ejes y articulaciones (manguetas) del sistema de dirección impreso en 3D.
* **Por qué se implementaron:** El Prototipo 1.0 usaba fricción directa plástico con plástico, lo que hacía que el giro fuera tosco.
* **Ventajas:** Reducen la fricción a casi cero, mejoran drásticamente la suavidad del giro y alargan la vida útil del MG90S.
* **Desventajas:** Requieren tolerancias de impresión 3D extremadamente precisas.

### 4.4. Sensores de Entorno

**Matriz de Sensores Ultrasónicos HC-SR04 (x3)**
![Sensor HC-SR04](https://github.com/user-attachments/assets/902c8c8b-0308-4dfd-9ffe-1c58e8a6bf10)

* **Función y Ubicación:** Sistema de detección primario. Uno frontal para detectar esquinas/muros finales y dos laterales para el control PID de seguimiento de carril.
* **Por qué se conservaron:** A pesar del ruido que presentan, con los algoritmos de filtrado correctos aplicados ahora en el ESP32, son suficientes.
* **Ventajas:** Económicos, fáciles de reemplazar y cubren perfectamente el rango de medición que requiere la pista.
* **Desventajas:** Sonido divergente (el haz se ensancha y puede rebotar mal si el carro choca en ángulo). 

---

## 🎯 5. Dimensiones de la Pista y Estrategia de Control

El diseño de *Dinoco 2.0* se adaptó estrictamente a las especificaciones del campo de juego descritas en el reglamento oficial de la WRO 2026 Futuros Ingenieros:

* **Área Total del Campo:** 3000 mm x 3000 mm (3 m x 3 m).
* **Ancho de Carril:** Carriles de circulación delimitados por paredes exteriores e interiores con secciones de entre 400 mm y 500 mm.

### Algoritmo de Control PID Adaptado
Heredamos y refinamos el algoritmo de **Control Proporcional-Integrativo-Derivativo (PID)** del software anterior:

1. **Lectura y Filtrado:** El ESP32 consulta cíclicamente los sensores ultrasónicos, aplicando un filtro por media móvil para eliminar picos erróneos.
2. **Cálculo de Error de Centrado:** Se determina la diferencia de distancia entre la pared izquierda y derecha: Error = Distancia Izquierda - Distancia Derecha.
3. **Corrección Angular:** La salida del PID ajusta en tiempo real la señal PWM hacia el servomotor de dirección.

---

## 🧠 6. Análisis de Fallas, Riesgos y Lecciones Aprendidas

> ⚡ **Problema: Caídas de voltaje (Brownouts) al arrancar el motor**
> * **Causa:** El motor DC exigía un pico de corriente al arrancar que bajaba la tensión por debajo de 3.3V, reiniciando el microcontrolador.
> * **Solución:** Separamos las líneas de alimentación implementando el LM2596.

> 🔊 **Problema: Lecturas erráticas en los sensores ultrasónicos**
> * **Causa:** El ruido acústico del aire y la vibración estructural generaban picos de lectura falsos.
> * **Solución:** Diseñamos una función de software que toma muestras consecutivas, descarta los valores extremos y calcula
## ⚡ 7. Esquemático y Diagrama Eléctrico

Para garantizar la reproducibilidad del proyecto y documentar la arquitectura de hardware, se diseñó el siguiente diagrama eléctrico que detalla la distribución de energía y el flujo de señales lógicas.

<img width="624" height="583" alt="WhatsApp Image 2026-09-05 at 21 27 21" src="https://github.com/user-attachments/assets/db9d122d-c823-46b4-8a68-e6280004689a" />

### 7.1. Distribución de Energía (Power Management)
El sistema cuenta con un circuito de alimentación segmentado para proteger la electrónica de control de los picos de consumo de los actuadores:
* **Fuente Principal:** Pack de 3 baterías 18650 (11.1V nominales) con un interruptor general (Switch 1).
* **Etapa de Potencia:** Los 11.1V van directos al módulo L298N para maximizar el torque del motor DC trasero.
* **Etapa de Control:** El voltaje se regula a través del módulo **LM2596 (Buck Converter)**, reduciéndolo a 5V estables. Esta línea pasa por un segundo interruptor (Switch 2) y alimenta de forma segura el ESP32 (vía pin VIN), el Servomotor MG90S y los sensores ultrasónicos.

### 7.2. Acondicionamiento de Señales lógicas
Dado que el ESP32 opera con lógica de 3.3V y los sensores ultrasónicos HC-SR04 devuelven pulsos de 5V en su pin *Echo*, se integró un **Conversor de Nivel Lógico Bidireccional (Level Shifter)** en el centro del circuito. Esto protege los pines GPIO del microcontrolador de sobretensiones.

### 7.3. Tabla de Conexiones (Pinout)

A continuación, se mapean las conexiones entre el microcontrolador ESP32 y los periféricos, basándose en el diagrama eléctrico oficial del equipo:

| Componente | Pin del Periférico | Pin ESP32 (GPIO) | Observaciones |
| :--- | :--- | :--- | :--- |
| **Sensor Ultrasónico (Frontal)** | TRIG <br> ECHO | GPIO 27 <br> GPIO 14 | *ECHO pasa por el Level Shifter (5V -> 3.3V)* |
| **Sensor Ultrasónico (Izquierdo)** | TRIG <br> ECHO | GPIO 15 <br> GPIO 2 | *ECHO pasa por el Level Shifter (5V -> 3.3V)* |
| **Sensor Ultrasónico (Derecho)** | TRIG <br> ECHO | GPIO 13 <br> GPIO 12 | *ECHO pasa por el Level Shifter (5V -> 3.3V)* |
| **Driver L298N (Motor DC)** | ENA (PWM) <br> IN1 <br> IN2 | GPIO 25 <br> GPIO 33 <br> GPIO 32 | *Control de velocidad y sentido del eje trasero* |
| **Servomotor MG90S** | Señal (PWM) | GPIO 26 | *Control del ángulo de dirección Ackermann* || Señal (PWM) | GPIO XX | *Control de ángulo de dirección Ackermann* |

---

## 📂 8. Guía de Reproducibilidad y Archivos del Repositorio
*( archivos STL de impresión 3D, etc.) 
<img width="1017" height="761" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM" src="https://github.com/user-attachments/assets/c7a4abef-6733-4fe5-a213-e5cf82d0b84e" />
<img width="1017" height="762" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM (9)" src="https://github.com/user-attachments/assets/c564897c-9a5f-4c65-85ae-d1d0399ae834" />
<img width="1022" height="763" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM (8)" src="https://github.com/user-attachments/assets/bac2ce1c-5610-449b-846e-d2791b75d907" />
<img width="1023" height="761" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM (7)" src="https://github.com/user-attachments/assets/dd5a533e-f80b-4b7a-a76b-0a599755b586" />
<img width="1023" height="758" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM (6)" src="https://github.com/user-attachments/assets/8ed62972-69ee-416f-8cee-5f832434c84e" />
<img width="1018" height="762" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM (5)" src="https://github.com/user-attachments/assets/a4c344bc-c646-4062-bc3c-24eb01402ba6" />
<img width="1021" height="771" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM (4)" src="https://github.com/user-attachments/assets/c4759f0d-7a7b-4b9c-841d-c3c377131d67" />
<img width="1023" height="761" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM (3)" src="https://github.com/user-attachments/assets/8ed91d1b-4361-4c11-8b1c-a2a5a8daf3c1" />
<img width="1007" height="762" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM (2)" src="https://github.com/user-attachments/assets/6d326884-1a5e-4521-b49a-b249676d4af9" />
<img width="1015" height="767" alt="WhatsApp Image 2026-09-06 at 7 58 35 PM" src="https://github.com/user-attachments/assets/ee570580-f0c0-4eba-84be-656a86f92799" />
<img width="1027" height="757" alt="WhatsApp Image 2026-09-06 at 7 58 36 PM (1)" src="https://github.com/user-attachments/assets/ad485d07-f50b-4fb6-b737-c08e7124e2e8" />

