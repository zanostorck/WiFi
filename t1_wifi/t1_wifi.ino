#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte maxLength = 16;
char buffer[maxLength];
int i=0;

void setup() {
  // Initialize both serial ports:
  Serial.begin(19200);
  
  // Initialize LCD display as 16x2:
  lcd.begin(16,2);
}

void loop() {
  // read from port 1, send to port 0:
  if (Serial.available()) {
    for(i=0;i<maxLength;i++){
      buffer[i] = Serial.read();
    }
    
    Serial.print("Received: ");
    Serial.print(buffer);
    Serial.print("\n");
  }

/*
 //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("FILIPEFLOP");
  lcd.setCursor(3, 1);
  lcd.print(" LCD 16x2");
  delay(5000);
  
  //Rolagem para a esquerda
  for (int posicao = 0; posicao < 3; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  
  //Rolagem para a direita
  for (int posicao = 0; posicao < 6; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }*/
  
}
