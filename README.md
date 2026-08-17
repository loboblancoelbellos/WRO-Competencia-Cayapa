# 🚀 WRO 2026 Future Engineers: Equipo Cayapa - Robot "Dinoco"

<p align="center">
  <img width="628" height="557" alt="Foto del Equipo Cayapa" src="https://github.com/user-attachments/assets/b61ea05f-7386-4244-ab09-d77db72ba0d4" />
</p>

> *Vehículo autónomo desarrollado por el equipo **Cayapa** para competir en la categoría Future Engineers de la World Robot Olympiad (WRO) 2026. Diseñado para la navegación autónoma, seguimiento de carril y esquive de obstáculos mediante un microcontrolador ESP32 y una matriz de sensores.*

---

## 📌 ÍNDICE
1. [Introducción y Datos del Equipo](#1-introducción-y-datos-del-equipo)
2. [Evolución e Iteraciones del Diseño Mecánico](#2-evolución-e-iteraciones-del-diseño-mecánico)
3. [Movilidad y Sistema de Tracción/Dirección](#3-movilidad-y-sistema-de-traccióndirección)
4. [Arquitectura de Hardware, Sensores y Energía](#4-arquitectura-de-hardware-sensores-y-energía)
5. [Estrategia y Algoritmos para los Desafíos](#5-estrategia-y-algoritmos-para-los-desafíos)
6. [Análisis de Fallas, Riesgos y Lecciones Aprendidas](#6-análisis-de-fallas-riesgos-y-lecciones-aprendidas)
7. [Guía de Reproducibilidad y Archivos del Repositorio](#7-guía-de-reproducibilidad-y-archivos-del-repositorio)

---

<a name="1-introducción-y-datos-del-equipo"></a>
## 👥 1. Introducción y Datos del Equipo

Este repositorio documenta el desarrollo integral de nuestro vehículo autónomo **"Dinoco"**. Como estudiantes de Ingeniería en Electrónica, aplicamos principios de control automático, diseño mecánico e integración de sistemas electromecánicos para cumplir con la normativa oficial de la WRO 2026.

### Miembros del Equipo
* **Leontino Jose Medina Di Donato** - *Desarrollo de Software y Algoritmos de Control*
* **Adriana Carolina Palmar Molero** - *Diseño de Circuitos, Sistema de Potencia y Cableado*
* **Nilecto Noe Leon Guerere** - *Diseño Mecánico, Modelado e Impresión 3D*

---

<a name="2-evolución-e-iteraciones-del-diseño-mecánico"></a>
## 🔄 2. Evolución e Iteraciones del Diseño Mecánico

El proceso de desarrollo de *Dinoco* siguió un enfoque iterativo basado en pruebas de campo para optimizar la distribución de peso, la rigidez estructural y la estabilidad de las lecturas de los sensores.

### Etapa 1: Selección del Chasis Base
Analizamos diferentes alternativas *Open Source* para el tren motriz y la dirección. Seleccionamos una estructura de chasis RC escala 1:10 por su adaptabilidad y factibilidad de fabricación mediante impresión 3D.
* **Referencia del Chasis:** [Chasis RC 1:10 en Cults3D](https://cults3d.com/es/modelo-3d/juegos/casis-1-10-adaptable)
* **Guía de referencia:** [Guía de Ensamblaje Chasis RC por DukeDoks](https://dukedoks.com/portfolio/guia-chasis-rc/)

![Chasis Referencia](https://github.com/user-attachments/assets/9e7c69a4-fcab-4fcb-8af9-bcbd09175e0b)

### Etapa 2: Iteraciones de Ensamblaje y Ajustes Estructurales
Durante las primeras pruebas de rodaje identificamos vibraciones que afectaban la precisión de los sensores ultrasónicos. Modificamos los soportes impresos e independizamos mecánicamente la estructura superior del tren de tracción.

| Vista Frontal | Vista Superior | Vista Lateral |
| :---: | :---: | :---: |
| [![Chasis 1](https://private-user-images.githubusercontent.com/147768482/452440916-3ea8a2ea-8c3c-4cf5-b728-1cdf928101bc.jpg)](link) | [![Chasis 2](https://private-user-images.githubusercontent.com/147768482/452440924-43a830bd-0473-43b1-a4c9-bbeb139ec016.jpg)](link) | [![Chasis 3](https://private-user-images.githubusercontent.com/147768482/452440921-7f2d57ec-28e8-406a-b306-d1da54f44467.jpg)](link) |

---

<a name="3-movilidad-y-sistema-de-traccióndirección"></a>
## ⚙️ 3. Movilidad y Sistema de Tracción/Dirección

### 3.1. Tracción Trasera: Motor Makeblock 9VDC (185 RPM)
<img width="250" align="right" alt="Motor Makeblock" src="https://github.com/user-attachments/assets/8a9cdd8b-57d4-416b-b355-9b4c4810f2ba" />

El movimiento longitudinal del robot es impulsado por un motor DC con caja reductora integrada.
* **Justificación de Ingeniería:** Elegimos este motor debido a su **elevado par de apriete (torque)** y caja reductora metálica de 185 RPM. Esto permite superar la inercia del chasis completo y mantener una velocidad constante incluso en aceleraciones bruscas.
* **Compensaciones (Trade-offs):** Su consumo de corriente e inductancia pueden generar ruido eléctrico. Para resolverlo, aislamos la etapa de potencia mediante el controlador L298N y aplicamos señales de modulación por ancho de pulso (PWM) para suavizar la aceleración.

### 3.2. Sistema de Dirección: Servomotor MG90S
<img width="220" align="right" alt="Servo MG90S" src="https://github.com/user-attachments/assets/8a5d8723-35ca-40f7-a34a-3fabfd5f0480" />

Encargado del control angular en el tren delantero mediante una geometría de dirección tipo Ackermann.
* **Justificación de Selección:** Optamos por el **MG90S** en lugar de servos estándar de plástico (como el SG90) porque cuenta con **engranajes metálicos (Metal Gear)**. Esto previene la rotura o deformación de los dientes mecánicos ante posibles colisiones accidentales contra las paredes de la pista.
* **Control:** Se gobierna mediante salidas PWM directas, ofreciendo una respuesta angular rápida y precisa para las correcciones de trayectoria.

<div style="clear: both;"></div>

---

<a name="4-arquitectura-de-hardware-sensores-y-energía"></a>
## 🔌 4. Arquitectura de Hardware, Sensores y Energía

### 4.1. Unidad Central de Procesamiento: ESP32
<img width="280" align="right" alt="ESP32" src="https://github.com/user-attachments/assets/acf25497-c3d1-482c-a017-23cde340d36b" />

**Justificación Tecnológica:** Seleccionamos el **ESP32** sobre arquitecturas tradicionales de 8 bits (como Arduino Uno). 
* **Ventajas:** Procesador Tensilica Dual-Core a 240 MHz con 520 KB de SRAM. Esto nos otorga la capacidad de procesamiento requerida para ejecutar filtrado numérico en tiempo real de los sensores y control de trayectoria sin demoras en el bucle principal.
* **Adaptación de Niveles Lógicos:** Dado que el ESP32 opera con lógica de 3.3V y los sensores ultrasónicos entregan señales de 5V, implementamos divisores de tensión / adaptadores de nivel lógico en los pines de recepción (RX/Echo) para proteger el microcontrolador.

### 4.2. Mat
