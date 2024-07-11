# Física - Conversor de Temperatura 

### Materiais:

### Arduino

<img src="image/Captura de tela 2024-07-10 111317.png" alt = "Arduino" width="200" height="150">

### Protoboard

<img src="image/Captura de tela 2024-07-10 111312.png" alt="Protoboard" width="250" height="200">


### Sensor de Temperatura 

<img src="image/Captura de tela 2024-07-10 211140.png" alt="Sensor De Temperatura" width="60" height="60">


## Quantidade de materias necessários
1. 1 Sensor de Temperatura ;
2. 3 Fios Jumpers
3. Software Arduino IDE / VSCode (PlatformIO)

## Objetivo

Experimento sobre demostrando na prática, a conversão de temperatura para diferente escalar de Celsius,Kelvin e Fahrenheit.


### Circuíto 


<img src="image/Captura de tela 2024-07-10 210907.png" alt="Circuíto Montado" width="500" height="">

### Esquema

<img src="image/Captura de tela 2024-07-10 212543.png   " alt="Esquema do Circuíto" width="500" height="">


## Código Para O Funcionamento do Arduíno 
```c++
const int temperaturaPin = A0;  // Pino onde o sensor de temperatura LM35 está conectado

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
 int sensorValue = analogRead(temperaturaPin); // Lê o valor do sensor de temperatura LM35
  float voltage = sensorValue * (5.0 / 1023.0); // Converte o valor analógico para voltagem
  float temperatureC = voltage * 100; // Converte a voltagem para temperatura em Celsius
  Serial.print( temperatureC   );
  float temperatureK = temperatureC + 273.15; // Converte Celsius para Kelvin
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0; // Converte Celsius para Fahrenheit

	delay(1000);
}


```

