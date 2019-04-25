#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define LED 2
#define BUZZER 14
#define SIGNAL 16

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SIGNAL, INPUT);

  digitalWrite(LED, HIGH);

  Serial.begin(115200);
  Serial.println("Alive and kicking");

  tone(BUZZER, 440);
  delay(500);
  
  noTone(BUZZER);
  delay(500);

  Serial.println("Commencing deep sleep");
  if(HIGH == digitalRead(SIGNAL)){
    ESP.deepSleep(0);
  }
}

void loop(){
  if(HIGH == digitalRead(SIGNAL)){
    ESP.restart();
  } else {
    tone(BUZZER, 440);
    delay(500);
    noTone(BUZZER);
    delay(500); 
  }
}