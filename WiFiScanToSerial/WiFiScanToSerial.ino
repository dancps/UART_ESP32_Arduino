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
#include <Wire.h>

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    
    //Serial.println("Setup done");
}

void loop()
{
    //Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    //Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        //Serial.print(n);
        //Serial.println(" networks found");
        for (int i = 0; i < 1; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    //Serial.println("");

    // Wait a bit before scanning again
    delay(500);
}
