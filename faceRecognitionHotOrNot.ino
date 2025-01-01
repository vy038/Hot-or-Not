#include <Servo.h>
Servo servo1;
char data;
int hotCounter = 0;
int notCounter = 0;
int hot = 2;


void setup(){
  Serial.begin(9600);
  servo1.attach(3);
  servo1.write(0);
  delay(2000);
  servo1.write(180);
  delay(2000);
  servo1.write(70);
  delay(2000);
}

void loop(){
  while(Serial.available()) {
    data = Serial.read();
  }
  switch(data) {
    case ('A'):
    hot = 1;
      break;
    case ('B'):
    hot = 0;
      break;
  }

  if (hot == 1) {
    servo1.write(180);
  } else if (hot == 0) {
    servo1.write(0);
  }
}