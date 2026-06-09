## 🚀 Documentacion de ingenieria - Cayapa

Este repositorio contiene todos los materiales necesarios para crear a "Dinoco", el robot autónomo creado por el equipo "Cayapa", que participará en la categoría Futuros ingeniero en la Clasificaion de la World Robot Olympiad en la temporada 2026.

##  Contenido 

- Miembros del equipo 
- Introduccion 
- Diseño adaptado 
- Materiales y Componentes


## 📖 Introducción
En este repositorio esta planteado el arduo proceso de diseño, armado y construccion del dispositivo, para la categoría Futuros Ingenieros de la WRO. Fue un proceso realizado con gran esfuerzo, independientemente de las dificultades. Un trabajo en equipo y dedicación para dar lo mejor de nosotros en la competencia, buscando la mejoria en cada area de la electronica, robotica y mecanica, ademas de basarnos en los conocimientos adquiridos en nuestro recorrido como estudiantes de Ingenieria en Eletronica, pensando siempre en adquirir un mayor conocimento y ser profesionales del mas alto nivel en nuestra area.




## Miembros del equipo 
-Leontino Jose Medina Di Donato

-Adriana Carolina Palmar Molero

-Nilecto Noe Leon Guerere

Somos jovenes estudiantes de ingeniería en electronica, nos conocimos en las aulas de la institucion como futuros ingenierosa, en nuestro trayecto se nos presento la oportunidad de ingresar a la competencia y decidimos participar, motivados por la pasión que compartimos de armar proyectos electronicos. La competencia nos permitio  expandir nuestros conocimientos de robótica, y explotar nuestras capacidades como un equipo que busca superar las expectativas propuestas por la competencia. 

<img width="628" height="557" alt="photo_2026-06-09_19-06-22" src="https://github.com/user-attachments/assets/b61ea05f-7386-4244-ab09-d77db72ba0d4" />




**Chasis de referencias de modelado 3D**

Al comienzo de nuestra inmersión para esta competencia, decidimos explotar al máximo todos los recursos disponibles a nuestra disposición, entre ellos los muchos modelos que hay en internet de modelado 3D para chasis, entre ellos encontramos uno que nos funcionaba en muchos factores, ya sea tiempo, factibilidad, estética, etc. Aquí dejamos el link a disposicion para mas información además de adjuntar la imagen de referencia y las imágenes de nuestro chasis post impresión 3D.




 https://cults3d.com/es/modelo-3d/juegos/casis-1-10-adaptable

![Chasis-RC-02](https://github.com/user-attachments/assets/9e7c69a4-fcab-4fcb-8af9-bcbd09175e0b)

### **Chasis Armado**

[![](https://private-user-images.githubusercontent.com/147768482/452440916-3ea8a2ea-8c3c-4cf5-b728-1cdf928101bc.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDkyMzc3MTksIm5iZiI6MTc0OTIzNzQxOSwicGF0aCI6Ii8xNDc3Njg0ODIvNDUyNDQwOTE2LTNlYThhMmVhLThjM2MtNGNmNS1iNzI4LTFjZGY5MjgxMDFiYy5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjA2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYwNlQxOTE2NTlaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hYWU5ZjdkZWI2OTg3MGQ3ZDA1YWY3M2M0NGQxZTM2NGY3ZWYzNDdhMmQ3MDA0YmI4ZmI1MTAwMWQzM2Q5ZjIxJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.gCb0gfFzAoQ2r3PP932QrQqkEkITuoaZtzW44D_CnMI)](http://https://private-user-images.githubusercontent.com/147768482/452440916-3ea8a2ea-8c3c-4cf5-b728-1cdf928101bc.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDkyMzc3MTksIm5iZiI6MTc0OTIzNzQxOSwicGF0aCI6Ii8xNDc3Njg0ODIvNDUyNDQwOTE2LTNlYThhMmVhLThjM2MtNGNmNS1iNzI4LTFjZGY5MjgxMDFiYy5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjA2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYwNlQxOTE2NTlaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hYWU5ZjdkZWI2OTg3MGQ3ZDA1YWY3M2M0NGQxZTM2NGY3ZWYzNDdhMmQ3MDA0YmI4ZmI1MTAwMWQzM2Q5ZjIxJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.gCb0gfFzAoQ2r3PP932QrQqkEkITuoaZtzW44D_CnMI)

[![chasis ](https://private-user-images.githubusercontent.com/147768482/452440924-43a830bd-0473-43b1-a4c9-bbeb139ec016.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDkyMzc3MTksIm5iZiI6MTc0OTIzNzQxOSwicGF0aCI6Ii8xNDc3Njg0ODIvNDUyNDQwOTI0LTQzYTgzMGJkLTA0NzMtNDNiMS1hNGM5LWJiZWIxMzllYzAxNi5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjA2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYwNlQxOTE2NTlaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mM2NhOTJjMzNlZGQxNDQ5ZjY1MGFhNjA1OTYwYjRhYTI3MWU3YjhlZjEwYjZmYmU5NmEzZWU2ZWMzMjQwOWJiJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.m79xnFxID8P_114g3x65EMjXeFpj_StbIAWnFPVMs9c "chasis ")](http://https://private-user-images.githubusercontent.com/147768482/452440924-43a830bd-0473-43b1-a4c9-bbeb139ec016.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDkyMzc3MTksIm5iZiI6MTc0OTIzNzQxOSwicGF0aCI6Ii8xNDc3Njg0ODIvNDUyNDQwOTI0LTQzYTgzMGJkLTA0NzMtNDNiMS1hNGM5LWJiZWIxMzllYzAxNi5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjA2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYwNlQxOTE2NTlaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mM2NhOTJjMzNlZGQxNDQ5ZjY1MGFhNjA1OTYwYjRhYTI3MWU3YjhlZjEwYjZmYmU5NmEzZWU2ZWMzMjQwOWJiJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.m79xnFxID8P_114g3x65EMjXeFpj_StbIAWnFPVMs9c "chasis ")

[![](https://private-user-images.githubusercontent.com/147768482/452440921-7f2d57ec-28e8-406a-b306-d1da54f44467.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDkyMzc3MTksIm5iZiI6MTc0OTIzNzQxOSwicGF0aCI6Ii8xNDc3Njg0ODIvNDUyNDQwOTIxLTdmMmQ1N2VjLTI4ZTgtNDA2YS1iMzA2LWQxZGE1NGY0NDQ2Ny5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjA2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYwNlQxOTE2NTlaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hM2M0YTk4MGJjZmViNDZjZTU3NWU5NGQ2YjViNjQ0Y2ZjZDU5ODQ1NjcyYWIxNzc3YTE0ZDk1OGI4MDRjN2YyJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.WmrkOCiTafj0QyTmyxjL1cyLML15lcGE_XQuN2gwS4o)](http://https://private-user-images.githubusercontent.com/147768482/452440921-7f2d57ec-28e8-406a-b306-d1da54f44467.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDkyMzc3MTksIm5iZiI6MTc0OTIzNzQxOSwicGF0aCI6Ii8xNDc3Njg0ODIvNDUyNDQwOTIxLTdmMmQ1N2VjLTI4ZTgtNDA2YS1iMzA2LWQxZGE1NGY0NDQ2Ny5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwNjA2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDYwNlQxOTE2NTlaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hM2M0YTk4MGJjZmViNDZjZTU3NWU5NGQ2YjViNjQ0Y2ZjZDU5ODQ1NjcyYWIxNzc3YTE0ZDk1OGI4MDRjN2YyJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.WmrkOCiTafj0QyTmyxjL1cyLML15lcGE_XQuN2gwS4o)

## **Guia de armado**
En esta seccion se encontraran con un paso a paso de nuestro proceso  de armado, una guia sencilla y completa de nuestro proceso. Para empezar se adjunta un link del armado del chasis a disposición pública, el cual utilizamos como recurso para optimizar mejor el tiempo.


https://dukedoks.com/portfolio/guia-chasis-rc/

### **Archivos de impresion de chasis y fotos de la impresion**



## 🔧 Materiales y Componentes
Lista detallada de los componentes utilizados:
- **Chasis de referencias de modelado 3D**
- **Motor DC 9V kit ultimate 2.0**
- **Servo Motor Futaba S3003 08-sd-025**
- **Arduino Mega 2560**
- **Batería de litio 18650 (3 UND)**
- **Puente H L298N**
- **Sensor de ultrasonido de distancia Arduino HC-SR04 (3 UND)**



**Servo motor MG90S**

<img width="1200" height="1200" alt="image" src="https://github.com/user-attachments/assets/8a5d8723-35ca-40f7-a34a-3fabfd5f0480" />



Descripción: Servo estándar de 180° usado en robótica y modelismo, con engranajes de nylon 214.

Ventajas:

1. Precisión: Control angular exacto mediante señales PWM 14.

2. Costo bajo: Opción económica para proyectos básicos 10.

3. Compatibilidad: Funciona con Arduino (ejemplo: control de brazos robóticos) 10.

Desventajas:

 1. Torque limitado: 3.2 kg/cm a 4.8V (insuficiente para cargas pesadas) 2.

2. Fragilidad: Engranajes de nylon propensos a desgaste 14.

3. Voltaje crítico: Requiere regulación precisa (recomendado 6V con UBEC)

**ESP32**

<img width="1000" height="529" alt="SBC-NodeMCU-ESP32-C_01" src="https://github.com/user-attachments/assets/acf25497-c3d1-482c-a017-23cde340d36b" />



✅ 3 Ventajas del Arduino Uno
Fácil de usar y aprender

Ideal para principiantes gracias a su entorno de desarrollo intuitivo y abundante documentación.

Gran comunidad y soporte

Miles de tutoriales, foros y ejemplos disponibles para resolver dudas y compartir proyectos.

Compatible con muchos módulos y sensores

Puedes conectar fácilmente pantallas, motores, sensores, y más sin complicaciones.

❌ 3 Desventajas del Arduino Uno
Capacidad limitada de memoria y procesamiento

Solo 32 KB de memoria flash y 2 KB de RAM, lo que restringe proyectos complejos.

Sin conectividad inalámbrica integrada

No incluye Wi-Fi ni Bluetooth, lo que requiere módulos adicionales para conectividad.

Tamaño relativamente grande

Puede ser incómodo para proyectos compactos o portátiles; hay placas más pequeñas como el Arduino Nano.


**Baterías De Litio 18650 3.7V a 7800mA**

[![](https://http2.mlstatic.com/D_NQ_NP_881915-MLV71037692218_082023-O.webp)](http://https://http2.mlstatic.com/D_NQ_NP_881915-MLV71037692218_082023-O.webp)

**Puente H L298N**

![Sin títulopuente h rojo](https://github.com/user-attachments/assets/c998e194-728f-4ca4-acd2-dbf268346189)

 **Sensor de ultrasonido de distancia Arduino HC-SR04**

![ultrasinico](https://github.com/user-attachments/assets/902c8c8b-0308-4dfd-9ffe-1c58e8a6bf10)
 
**Switches** 

[![suiche](https://sumador.com/cdn/shop/products/Suichetipobalancinde2pines2.jpg?v=1588622314 "suiche")](http://https://sumador.com/cdn/shop/products/Suichetipobalancinde2pines2.jpg?v=1588622314 "suiche")

**Motor Makeblock 9VDC de 185 RPM**

![motor makeblock 9v](https://github.com/user-attachments/assets/8a9cdd8b-57d4-416b-b355-9b4c4810f2ba)

### **Descripcion**

El motor Makeblock 9VDC de 185 RPM es el motor más comúnmente utilizado en la plataforma Makeblock o proyectos de robotica en general. Está impulsado por corriente continua y es la opción ideal para que las cosas se muevan en todo tipo de proyectos.

### Ventajas:

1. Alto torque: Ideales para cargas medias gracias a su caja reductora (ejemplo: 185 RPM para modelos de 9V) 

2. Compatibilidad: Integrados con placas como MegaPi (basada en Arduino Mega 2560) 

3. Durabilidad: Piezas de aluminio anodizado en el kit Ultimate 2.0 9.

#### Desventajas:

1. Consumo energético: Requieren baterías de 9V (6xAA) o fuente externa 13.

2. Control complejo: Necesitan drivers como el L298N para PWM 9.

3. Ruido: Los engranajes pueden generar sonido en cargas altas 


### End
