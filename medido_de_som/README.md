# Física - Detector de Som

### Materiais:

Arduino.

<img src="image/Captura de tela 2024-07-10 111317.png" alt="Arduino" width="200" height="100">

Protoboard.

<img src="image/Captura de tela 2024-07-10 111312.png" alt="Protoboard" width="200" height="100">


Microfone , Resistor e Led Respectivamente.

<img src="image/Captura de tela 2024-07-10 111322.png" alt="Microfone" width="50" height="50">
<img src="image/Captura de tela 2024-07-10 111327.png" alt="Resistor" width="50" height="50">
<img src="image/Captura de tela 2024-07-10 111330.png" alt="Led" width="50" height="50">

## Quantidade de materias necessários
1. 1 Microfone;
2. 5 Resistências;
3. 5 Leds de cores variadas;
4. 9 Fios Jumpers
5. Software Arduino IDE / VSCode (PlatformIO)

## Objetivo

Experimento sobre propagação do som, a qual consiste em medir até onde o som está sendo propagando e a sua altura.

## Passo a Passo 

### Circuíto 


<img src="image/image.png" alt="Arduino" width="500" height="">

### Esquema

<img src="image/Captura de tela 2024-07-10 113840.png" alt="Arduino" width="500" height="">


## Código Para O Funcionamento do Arduíno 
```c++
//Definição de ondes os led estão conectados no arduino
int led_vermelho1=13; 
int led_vermelho2=12;
int led_amarelo=11;
int led_verde1=10;
int led_verde2=9;
//Porta analógia em que o microfone está conectado
int microfone=A0;
void setup()
{
//Inicializado a entrada dos componentes, os led estão mandando uma informação
  pinMode(led_vermelho1, OUTPUT);
  pinMode(led_vermelho2, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde1, OUTPUT);
  pinMode(led_verde2, OUTPUT);
}

void loop()
{
//Capitar o sinal do sensor
  int sensorValue = analogRead(microfone);
//Valores que iram reagião com o barulho do microfone
  digitalWrite(led_vermelho1,sensorValue>20);
  digitalWrite(led_vermelho2,sensorValue>120);
  digitalWrite(led_amarelo,sensorValue>400);
  digitalWrite(led_verde1,sensorValue>550);
  digitalWrite(led_verde2,sensorValue>600);
}
```

