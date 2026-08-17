# 🚀 WRO 2026 Future Engineers: Equipo Cayapa - Robot "Dinoco"

<p align="center">
  <img width="628" height="557" alt="Foto del Equipo Cayapa" src="https://github.com/user-attachments/assets/b61ea05f-7386-4244-ab09-d77db72ba0d4" />
</p>

> *Vehículo autónomo de diseño compacto desarrollado por el equipo **Cayapa** para competir en la categoría Future Engineers de la World Robot Olympiad (WRO) 2026. Diseñado para optimizar el radio de giro, la estabilidad estructural y la velocidad de procesamiento mediante un microcontrolador ESP32 y una matriz de sensores ultrasónicos.*

---

## 📌 ÍNDICE
1. [Introducción y Datos del Equipo](#1-introducción-y-datos-del-equipo)
2. [Evolución e Iteraciones del Diseño Mecánico](#2-evolución-e-iteraciones-del-diseño-mecánico)
   - [2.1 Prototipo 1.0 (Arduino Mega & Chasis RC 45x20 cm)](#21-prototipo-10-chasis-rc-modificado-y-arquitectura-basada-en-arduino-mega)
   - [2.2 Dinoco 2.0 (Diseño Compacto & ESP32)](#22-dinoco-versión-20--actual-optimización-dimensional-y-upgrade-electrónico)
3. [Movilidad y Sistema de Tracción/Dirección](#3-movilidad-y-sistema-de-traccióndirección)
4. [Arquitectura de Hardware, Sensores y Energía](#4-arquitectura-de-hardware-sensores-y-energía)
5. [Dimensiones de la Pista y Estrategia de Control](#5-dimensiones-de-la-pista-y-estrategia-de-control)
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

El desarrollo de *Dinoco* ha sido un proceso estrictamente iterativo, donde cada modificación respondió a fallas diagnosticadas durante pruebas dinámicas en pista.

### 2.1. Prototipo 1.0: Chasis RC Modificado y Arquitectura Basada en Arduino Mega

#### 📐 Motivación y Selección Mecánica Inicial
Debido a las restricciones de tiempo en la fase inicial del proyecto, el equipo optó por no diseñar un chasis desde cero. En su lugar, se seleccionó como plataforma de pruebas un chasis comercial de radiocontrol (RC) de dimensiones iniciales de **45 cm de largo por 20 cm de ancho**. Para adecuarlo al reglamento, se redujo la longitud recortando la estructura central.

* **Sistema de Tracción:** Transmisión por eje posterior rígido hacia ambas ruedas traseras.
* **Sistema de Dirección:** Servomotor **MG995**, seleccionado por su elevado par de apriete (torque).

#### 🔌 Arquitectura Electrónica y Sistema de Alimentación
* **Procesamiento:** Microcontrolador **Arduino Mega**.
* **Alimentación y Regulación:** Fuente de 12V con puente H para el motor principal y regulador lineal **LM7805** para alimentar a 5V la matriz de tres sensores ultrasónicos (HC-SR04).

#### 🔬 Diagnóstico Crítico de Fallas (¿Por qué falló el Prototipo 1.0?)
1. **Radio de Giro Ineficiente:** Con dimensiones cercanas al límite máximo, el vehículo requería un radio de viraje sumamente amplio, siendo incapaz de completar curvas de 90° cerradas o ejecutar el estacionamiento autónomo.
2. **Ruido Inductivo (Back-EMF):** El servomotor MG995 inyectaba picos de corriente hacia el pin de señal del Arduino Mega, provocando bloqueos aleatorios del programa.
3. **Sobrecarga Térmica y Caídas de Tensión (Brownouts):** El regulador LM7805 sufría sobrecalentamiento por la demanda simultánea de los sensores y el servo, ocasionando lecturas erráticas y reinicios constantes.

---

### 2.2. Dinoco (Versión 2.0 / Actual): Optimización Dimensional y Upgrade Electrónico

Tras analizar las limitaciones mecánicas y eléctricas del Prototipo 1.0, rediseñamos la plataforma desde cero para crear **Dinoco 2.0**, enfocándonos en la ergonomía, la velocidad de procesamiento y la modularidad.

| Vista del Chasis Actual | Ensamblaje de Componentes |
| :---: | :---: |
| <img src="https://github.com/user-attachments/assets/e0d9c0b3-902e-4ee5-a17e-8eaeda4a3df8" width="320"/> | <img src="https://github.com/user-attachments/assets/95f1f868-d955-4f10-abb5-973fc1276702" width="320"/> |

#### 📏 Reducción Ergonométrica de Dimensiones
* **Longitud Reducida:** Pasó de 45 cm a una longitud compacta entre **23 cm y 25 cm**.
* **Ancho Reducido:** Se optimizó a **15 cm de ancho**.
* **Beneficio en Pista:** Esta disminución drástica del volumen mejora significativamente la maniobrabilidad del robot dentro de los carriles de la pista, permitiéndole trazar curvas cerradas a mayor velocidad sin riesgo de colisión lateral.

#### ⚙️ Reutilización del Tren Motriz y Dirección Simplificada con Rodamientos
* **Transmisión Trasera:** Se optó por mantener la motorización DC Makeblock sobre eje rígido. Se descartó la implementación de un sistema diferencial impreso en 3D debido al alto costo en tiempo de modelado, ajuste y adaptación mecánica, priorizando la confiabilidad del conjunto.
* **Sistema de Dirección Ackermann:** Se rediseñó el tren delantero integrando **rodamientos (rolineras)** en los manguetas de dirección. Esto reduce drásticamente la fricción mecánica, elimina el juego holgado y permite que un servomotor más liviano mantenga un control angular preciso.

#### 🧠 Migración al Microcontrolador ESP32 + Shield Expansor
* **Capacidad de Cómputo:** Reemplazamos el Arduino Mega por un **ESP32**, aprovechando su arquitectura Dual-Core a 240 MHz, mayor memoria RAM y buffers de comunicación más amplios para el procesamiento del algoritmo PID.
* **Módulo Shield Expansor (Base Board):** Montamos el ESP32 sobre una placa de expansión de pines. Esto organiza el cableado, mejora la disipación térmica y facilita las labores de mantenimiento o sustitución rápida de componentes durante la competencia.

---

<a name="3-movilidad-y-sistema-de-traccióndirección"></a>
## ⚙️ 3. Movilidad y Sistema de Tracción/Dirección

### 3.1. Tracción Trasera: Motor DC Makeblock 9V (185 RPM)
<img width="220" align="right" alt="Motor Makeblock" src="https://github.com/user-attachments/assets/8a9cdd8b-57d4-416b-b355-9b4c4810f2ba" />

* **Justificación de Selección:** Proporciona un **alto par motor (torque)** gracias a su caja reductora metálica, manteniendo constante la tracción de las ruedas traseras.
* **Control de Velocidad:** Gobernado a través de señales PWM mediante el controlador Puente H L298N.

### 3.2. Dirección delantera tipo Ackermann con Rodamientos
<img width="200" align="right" alt="Servo MG90S" src="https://github.com/user-attachments/assets/8a5d8723-35ca-40f7-a34a-3fabfd5f0480" />

* **Mecanismo:** Geometría Ackermann equipada con **rodamientos (rolineras)** en los puntos de pivote para minimizar el rozamiento.
* **Actuador:** Servomotor **MG90S con engranajes metálicos**, evitando desgastes por colisión y garantizando un ángulo de giro suave y rápido.

<div style="clear: both;"></div>

---

<a name="4-arquitectura-de-hardware-sensores-y-energía"></a>
## 🔌 4. Arquitectura de Hardware, Sensores y Energía

Para el diseño de **
