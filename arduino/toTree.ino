#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>
#include "DHT.h"
DHT dht;
#define ssid "oil999"
#define pass "wozo8573"

#define FIREBASE_HOST "tree-f7129.firebaseio.com"
#define FIREBASE_AUTH "vg2i91ey98tv3KDwFOAYl95r4PJFIMzShlhJzTNJ"

int sensorPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   pinMode(D0,OUTPUT);
  dht.setup(D2); // data pin 2
  while(WiFi.status()!= WL_CONNECTED){
    Serial.print(".");
    Serial.println();
    delay(500);
    }
   Serial.print("Connected");
}

void loop() {
  sensorValue = ( 100.00 - ((analogRead(sensorPin)/1023.00) * 100.00));
  Serial.print(sensorValue);
  Firebase.setInt("soilNow", sensorValue);
  Serial.print("\n");
  String soil = Firebase.getString("soilMoistureBase");
  int soilint = soil.toInt();
  Serial.println(soilint);
  delay(dht.getMinimumSamplingPeriod());  
  float humidity = dht.getHumidity();
  if(sensorValue < soilint){
    digitalWrite(D0,HIGH);
  }else{
    digitalWrite(D0,LOW);
  }
  if(!isnan(humidity)){
      Serial.print("Humi ");
      Serial.print(dht.getHumidity());
      Firebase.setInt("humidityNow", dht.getHumidity());
      Serial.print("\n");
      Serial.print("temp ");
      Serial.print(dht.getTemperature());
      Firebase.setInt("temperatureNow", dht.getTemperature());
      Serial.print("\n");
    }
  delay(dht.getMinimumSamplingPeriod());
}
