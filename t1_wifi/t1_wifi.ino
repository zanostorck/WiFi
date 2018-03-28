#include <LiquidCrystal.h>

/*Configuração dos pinos do display LCD*/
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*Definições adicionais*/
const byte maxLength = 32;  /*Tamanho máximo do buffer serial*/
char buffer[maxLength];     /*Buffer serial*/
boolean newData = false;    /*Controle do fluxo de dados via serial*/

void setup() {
  /*Inicializa serial: 19200 = BT baud rate*/
  Serial.begin(19200);

  /*Inicializa display e exibe mensagem de boas vindas*/
  lcd.begin(16,2);
  lcd.print("Bem vindo!");
}

void loop() {
  readData();
  displayData();
}

/*---------------------------------------------------------
  Função readData():
  - Usada para ler os dados da serial
  - Controle é realizado baseado no caractere de nova linha
    '\n', pois quando este é recebido, é o sinal de que a 
    transmissão da mensagem acabou
  - Utiliza a variavel global newData para controle da 
    exibição dos dados
  ---------------------------------------------------------
*/
void readData(){
  static byte i = 0;
  char received;
  char endMarker = '\n';
  
  while(Serial.available() > 0 && newData == false){
    received = Serial.read();

    if(received != endMarker){
      buffer[i] = received;
      i++;

      if(i >= maxLength){
        i = maxLength - 1;      
      }      
    }
    else{
      buffer[i] = '\0';
      i = 0;
      newData = true;      
    }  
  } 
}

/*---------------------------------------------------------
  Função displayData():
  - Usada para exibir os dados no terminal e no display LCD
  ---------------------------------------------------------
*/
void displayData(){
  if(newData == true){
    
    Serial.print("Received: ");
    Serial.println(buffer);
    
    lcd.clear();
    lcd.setCursor(0, 0); //First row
    lcd.write(buffer);

    newData = false;
  }  
}



  

