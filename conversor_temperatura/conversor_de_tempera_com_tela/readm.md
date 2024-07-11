# Física - Conversor de Temperatura 

### Materiais:

### Arduino

<img src="image/Captura de tela 2024-07-10 111317.png" alt = "Arduino" width="200" height="150">

### Protoboard

<img src="image/Captura de tela 2024-07-10 111312.png" alt="Protoboard" width="250" height="200">

### Tela LCD

<img src="image/Captura de tela 2024-07-10 211054.png" alt="Tela LCD" width="250" height="200">

### Resistor e Sensor de Temperatura (Respectivamente)

<img src="image/Captura de tela 2024-07-10 111327.png" alt="Resistência" width="60" height="60">
<img src="imagem/Captura de tela 2024-07-10 211140.png" alt="Sensor De Temperatura" width="60" height="60">


## Quantidade de materias necessários
1. 1 Resistor;
2. 1 Sensor de Temperatura ;
3. 17 Fios Jumpers
4. 1 Tela LCD   
5. Software Arduino IDE / VSCode (PlatformIO)

## Objetivo

Experimento sobre demostrando na prática, a conversão de temperatura para diferente escalar de Celsius,Kelvin e Fahrenheit.


### Circuíto 


<img src="image/conversor de temperatua com tela.png" alt="Circuíto Montado" width="500" height="">

### Esquema

<img src="image/Captura de tela 2024-07-10 212601.png" alt="Esquema do Circuíto" width="500" height="">


## Código Para O Funcionamento do Arduíno 
```c++
#include <LiquidCrystal.h> //include para ter acesso as funções do lcd

const int temperaturaPin = A0; // Pino onde o sensor de temperatura LM35 está conectado
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); // Pinos que estão conectado no lcd

int backLight = 13; // Pino 13 responsável pelo controle do LED do backlight (luz de fundo)

void setup() {
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // Liga o backlight. Troque HIGH por LOW para desligar.
  lcd.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas
  lcd.clear(); // Limpa o display inicialmente
  Serial.begin(9600); // Inicializa a comunicação serial em 9600 bps
}

void loop() {
  int sensorValue = analogRead(temperaturaPin); // Lê o valor do sensor de temperatura 
  float voltage = sensorValue * (5.0 / 1023.0); // Converte o valor analógico para voltagem
  float temperatureC = voltage * 100; // Converte a voltagem para temperatura em Celsius
  float temperatureK = temperatureC + 273.15; // Converte Celsius para Kelvin
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0; // Converte Celsius para Fahrenheit

  // Exibe as temperaturas no terminal
  Serial.print("Temperatura em Celsius: ");
  Serial.print(temperatureC, 3); // Exibe com 3 casas decimais
  Serial.print(" °C, ");
  
  Serial.print("Temperatura em Kelvin: ");
  Serial.print(temperatureK, 3); // Exibe com 3 casas decimais
  Serial.print(" K, ");
  
  Serial.print("Temperatura em Fahrenheit: ");
  Serial.print(temperatureF, 3); // Exibe com 3 casas decimais
  Serial.println(" °F");

  // Exibe a temperatura em Celsius no LCD por alguns segundos
  lcd.clear(); // Limpa o display
  lcd.setCursor(3, 0); // Posiciona o cursor na coluna 0, linha 0
  lcd.print("Celsius(C) ");
  lcd.setCursor(5, 1);
  lcd.print(temperatureC, 3); // Exibe a temperatura em Celsius com 1 casa decimal

  delay(1000); // Aguarda 3 segundos antes de mudar para a próxima temperatura

  // Exibe a temperatura em Kelvin no LCD por alguns segundos
  lcd.clear(); // Limpa o display
  lcd.setCursor(4, 0); // Posiciona o cursor na coluna 0, linha 0
  lcd.print("Kelvin(K) ");
  lcd.setCursor(5, 1);
  lcd.print(temperatureK, 3); // Exibe a temperatura em Kelvin com 1 casa decimal

  delay(1000); // Aguarda 3 segundos antes de mudar para a próxima temperatura

  // Exibe a temperatura em Fahrenheit no LCD por alguns segundos
  lcd.clear(); // Limpa o display
  lcd.setCursor(2, 0); // Posiciona o cursor na coluna 0, linha 0
  lcd.print("Fahrenheit(F)");
  lcd.setCursor(5, 1);
  lcd.print(temperatureF, 3); // Exibe a temperatura em Fahrenheit com 1 casa decimal

  delay(1000); // Aguarda 3 segundos antes da próxima leitura
}

```

