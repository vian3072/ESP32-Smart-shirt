/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>



// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "zkW3CO_svMDePJY-7vCs4uLpPIfuBR5u";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Testing";
char pass[] = "test1234";

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
}

BLYNK_READ(V0) {
 //Blynk.virtualWrite(V0 ,(touchRead(2)));
 float temp = (analogRead(4)); 
 Serial.println(temp);
 Blynk.virtualWrite(V0, temp); 
}
BLYNK_READ(V1) {
 Blynk.virtualWrite(V1 ,(touchRead(14)));
}

BLYNK_READ(V2) {
 Blynk.virtualWrite(V2 ,(touchRead(13)));
}

BLYNK_READ(V3) {
 Blynk.virtualWrite(V3 ,(touchRead(12)));
}



void loop()
{
  float temp = (analogRead(4)); 
 Serial.println(temp);
  Blynk.run();
  
}
