/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 *  
 *  Pins:
 *  Vin -> 5V do Arduino
 *  GND -> GND do Arduino
 *  TX0 -> LV4 do conv logico 
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
#include "WiFi.h"
#include "HardwareSerial.h"
#include <Wire.h>

HardwareSerial UART0(0);

HardwareSerial UART1(1);

HardwareSerial UART2(2);

void setup()
{
    //Serial.begin(115200);
    

    UART0.begin(115200);
    UART1.begin(115200,SERIAL_8N1,5,18);
    UART2.begin(115200);
    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    
}

void loop(){
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    if (n == 0) {
        UART0.println("no networks found");
        //UART1.println("no networks found");
        UART2.println("no networks found");
    } else {
        for (int i = 0; i < 3; ++i) {
            // Print SSID and RSSI for each network found
            /*UART0.print(i + 1);
            UART0.print(": ");
            UART0.print(WiFi.SSID(i));
            UART0.print(" (");
            UART0.print(WiFi.RSSI(i));
            UART0.print(")");
            UART0.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");*/
            if(i==0){  
              UART0.print(i + 1);
              UART0.print(": ");
              UART0.print(WiFi.SSID(i));
              UART0.print(" (");
              UART0.print(WiFi.RSSI(i));
              UART0.print(")");
              UART0.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            }
            else if(i==1){
              UART1.print(i + 1);
              UART1.print(": ");
              UART1.print(WiFi.SSID(i));
              UART1.print(" (");
              UART1.print(WiFi.RSSI(i));
              UART1.print(")");
              UART1.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            }
            else if(i==2){
              UART2.print(i + 1);
              UART2.print(": ");
              UART2.print(WiFi.SSID(i));
              UART2.print(" (");
              UART2.print(WiFi.RSSI(i));
              UART2.print(")");
              UART2.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            }

            
            delay(10);
        }
    }
    // Wait a bit before scanning again
    delay(100);
}
