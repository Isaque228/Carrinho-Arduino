# Projeto de Carrinho Controlado por PS2 com Arduino

Este projeto utiliza um **Arduino Uno R3** para controlar um carrinho de controle remoto com um **controle de PS2**. O carrinho é alimentado por duas baterias 18650 e tem as seguintes funcionalidades:
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
- **Duas baterias 18650**

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
- **Buzina** ativada com um botão no controle PS2.
- **Direção** controlada por um **servo motor**.

## Como Usar

1. Monte o circuito conforme o esquema de montagem.
2. Faça o upload do código para o **Arduino Uno R3**.
3. Ligue o carrinho com as **baterias 18650**.
4. Use o **controle PS2** para controlar o carrinho.

## Dependências

Para rodar o código, você precisará das seguintes bibliotecas no Arduino IDE:

- Biblioteca **Servo.h** para controle do servo motor.
- Biblioteca **PS2X_lib** para comunicação com o controle PS2.
- Biblioteca **AFMotor** para controle da ponte H (se necessário).

## Alimentação

O projeto utiliza duas baterias 18650, que são conectadas diretamente ao Arduino para alimentar todos os componentes. Verifique a polaridade correta ao conectar as baterias.
