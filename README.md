# Projeto de Carrinho Controlado por um controle de PS2 com Arduino

Este projeto utiliza um **Arduino Uno R3** para controlar um carrinho de controle remoto com um **controle de PS2** o receptor foi adaptado para conectar ao arduino. O carrinho é alimentado por um powerbank e tem as seguintes funcionalidades:
- Controle da direção usando um **servo motor**
- Movimento para frente e para trás com um **motor DC** controlado por uma **ponte H**
- **Buzina** ativada com um **buzzer**

## Componentes Utilizados

- **Arduino Uno R3**
- **Servo Motor** para controlar a direção
- **Ponte H L298N** para controlar o motor DC
- **Motor DC** para o movimento do carrinho (frente e ré)
- **Buzzer** como buzina
- **Carrinho de controle remoto** (estrutura/base)
- **Controle PS2 wireless** com **receptor**
- **Um powerbank de 5v**

## Esquema de Montagem

- O **servo motor** é conectado ao pino digital do Arduino para controlar a direção.
- O **motor DC** é controlado pela **ponte H L298N**, que é conectada ao Arduino para controle do movimento (frente e ré).
- O **buzzer** é conectado a um pino digital do Arduino e usado como buzina.
- O **controle PS2** envia comandos para o Arduino via o **receptor PS2**, que controla o movimento e a direção do carrinho.
- As **baterias 18650** fornecem energia para o Arduino e o sistema de motores.

## Conexões

 **Modelo das conexões sera criado e publicado em breve**

## Funcionalidades

- Controle total do carrinho com o **controle PS2**: aceleração, ré e direção.
- **Buzina** ativada com o botão bolinha no controle.
- **Direção** controlada por um **servo motor**.
  
## Dependências

Para rodar o código, você precisará das seguintes bibliotecas no Arduino IDE:

- Biblioteca **Servo.h** para controle do servo motor.
- Biblioteca **PS2X_lib** para comunicação com o controle PS2.
- Biblioteca **AFMotor** para controle da ponte H (se necessário).

