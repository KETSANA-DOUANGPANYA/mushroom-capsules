#include <Arduino.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>

#define DHTTYPE DHT22


float humids[2];
float temps[2];
int RelayFan = 4;
int RelayPum = 0;

DHT dht[] = {{5, DHTTYPE}, {16, DHTTYPE}};
void setup() {
 Serial.begin(115200);
 Serial.println("esp Test");



  for (auto &sensor : dht)
  {
    sensor.begin();
  }
 pinMode(RelayFan,OUTPUT);
 pinMode(RelayPum,OUTPUT);
}


void loop() {

   digitalWrite(RelayFan,HIGH);
   digitalWrite(RelayPum,HIGH);
   Serial.println("on");
   delay(20000);
digitalWrite(RelayFan,LOW);
digitalWrite(RelayPum,LOW);
Serial.println("off");
delay(20000);
 for (int index = 0; index < 2; index++)
  {
    humids[index] = dht[index].readHumidity();
    temps[index] = dht[index].readTemperature();
  }

  if (isnan(humids[0])){
    Serial.println("\nHumindity 1 is not detected");
  }else {
    Serial.printf("humid 1: %f", humids[0]);
    Serial.printf("\ttemp 1: %f", temps[0]);
  }
   if (isnan(humids[1])){
    Serial.println("\nHumindity 1 is not detected");
  }else {
    Serial.printf("humid 2: %f", humids[1]);
    Serial.printf("\t\ntemp 2: %f", temps[1]);
  }
  
  delay(2000);
}



