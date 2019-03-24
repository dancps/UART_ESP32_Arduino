/*
 *  Esse código le o que recebe do ESP.
 *  
 *  Pins:
 *  0 -> HV4 do conv logic -> TX0 do ESP32 (recebe info)
 *  A4 -> SCA I2C
 *  A5 -> SCL I2C
 *  
 *  Para esse programa foi usado um arduino conectado com o ESP32
 *  O ESP envia os dados presentes nesse código por meio da saida
 *  TX0 e o Arduino recebe em sua porta RX. Após isso é printado 
 *  na tela LCD I2C o wifi de maior intensidade.
 *  
 *  PS: é importante que TODAS as comunicações entre o ESP32 e o
 *  Arduino sejam feitas com intermedio de um conversor de nível 
 *  lógico, visto que o Arduino trabala em 5V e o ESP32 em 3.3V.
 *  
 *  
 *  Talvez isso seja bom:
 *  https://github.com/Robot-Will/Stino
 */

#include "Wire.h"
#include "LiquidCrystal_I2C.h"
int lcdColumns = 16;
int lcdRows = 2;
int incomingByte = 0; 

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  lcd.begin (16,2);// initialize LCD
}

void loop() {
  // send data only when you receive data:
    
  //lcd.clear();
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    
    Serial.println(Serial.readString());
  }
  
  // put your main code here, to run repeatedly:
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("ESP32:");
  lcd.setCursor(0,1);
  lcd.print(Serial.readString());
  delay(1000);
}
