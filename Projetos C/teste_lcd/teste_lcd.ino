#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.begin();

}


void loop() {
  float numero = 10.12345; // Número com muitas casas decimais
  lcd.clear(); // Limpa o display
  lcd.setCursor(0, 0); // Posiciona o cursor
  
  // Converte o número em uma string com 2 casas decimais e concatena
  lcd.print("Celsius(C):" + String(numero, 2)); // Formata com 2 casas decimais
  
  delay(1000);
}



