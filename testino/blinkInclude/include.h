
#include <Arduino.h>

int led = 13;

void Blink(int pin) {
  digitalWrite ( pin, HIGH);
  delay(400);
  digitalWrite ( pin, LOW);
  delay(400);
}

void setup (){
  pinMode (led,OUTPUT);
}

// test
