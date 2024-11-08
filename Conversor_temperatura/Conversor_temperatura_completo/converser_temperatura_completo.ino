#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Neste caso é o pino 2, mais pode usar qualquer pino digital
#define ONE_WIRE_BUS 2

//Instacia o Objeto oneWire e Seta o pino do Sensor para iniciar as leituras
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

int led_verde=8;
int led_azul=9;
int led_amarelo=10;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  sensor.begin();
  Serial.begin(9600);
  pinMode(led_verde,OUTPUT);
  pinMode(led_azul,OUTPUT);
  pinMode(led_amarelo,OUTPUT);
}

void loop() {
  sensor.requestTemperatures();
  // A temperatura em Celsius para o dispositivo 1 no índice 0 (é possivel ligar varios sensores usando a mesma porta do arduino)
  float leitura = sensor.getTempCByIndex(0);
  float temperaturac = leitura;
  float temperaturaK = leitura + 273.15; // Converte Celsius para Kelvin
  float temperaturaF = (temperaturac * 9.0 / 5.0) + 32.0; // Converte Celsius para Fahrenheit

  //Exibe as temperaturas no terminal
  Serial.println("Temperatura em Celsius:");
  Serial.println(temperaturac, 3); // Exibe com 3 casas decimais
  
  Serial.println("Temperatura em Kelvin:");
  Serial.println(temperaturaK, 3); // Exibe com 3 casas decimais
  
  Serial.println("Temperatura em Fahrenheit: ");
  Serial.println(temperaturaF, 3); // Exibe com 3 casas decimais

  // Exibe a temperatura em Celsius no LCD por alguns segundos
  lcd.clear(); // Limpa o display
  lcd.setCursor(3, 0); // Posiciona o cursor na coluna 0, linha 0
  lcd.println("Celsius(C) ");
  lcd.setCursor(5, 1);
  lcd.println(temperaturac, 3); // Exibe a temperatura em Celsius com 1 casa decimal
  digitalWrite(led_verde, HIGH);
  delay(3000); // Aguarda 3 segundos antes de mudar para a próxima temperatura
  digitalWrite(led_verde, LOW);

  // Exibe a temperatura em Kelvin no LCD por alguns segundos
  lcd.clear(); // Limpa o display
  lcd.setCursor(4, 0); // Posiciona o cursor na coluna 0, linha 0
  lcd.println("Kelvin(K) ");
  lcd.setCursor(5, 1);
  digitalWrite(led_azul, HIGH);
  lcd.println(temperaturaK, 3); // Exibe a temperatura em Kelvin com 1 casa decimal
  delay(3000); // Aguarda 3 segundos antes de mudar para a próxima temperatura
  digitalWrite(led_azul, LOW);
  

  // Exibe a temperatura em Fahrenheit no LCD por alguns segundos
  lcd.clear(); // Limpa o display
  lcd.setCursor(2, 0); // Posiciona o cursor na coluna 0, linha 0
  lcd.println("Fahrenheit(F)");
  lcd.setCursor(5, 1);
  lcd.println(temperaturaF, 3); // Exibe a temperatura em Fahrenheit com 1 casa decimal
  digitalWrite(led_amarelo,HIGH);
  delay(3000); // Aguarda 3 segundos antes da próxima leitura
  digitalWrite(led_amarelo,LOW);
}