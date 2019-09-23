#include "PS2Mouse.h"
//3 -> clock, 2 -> DATA
PS2Mouse mouse(3,2);
//fire, Up, Down, Left, Right
int joystick[] = {4,5,6,7,8};

uint8_t stat;
int x,y;

int treshold = 15;

void setup(){
  mouse.begin();

  for(int i = 0; i < 5; i++){
    pinMode(joystick[i], OUTPUT);
    digitalWrite(joystick[i], HIGH);
  }
}

void loop(){
  mouse.getPosition(stat,x,y);
  bool leviKlik = stat % 2;
  stat = stat / 2;
  bool desniKlik = stat % 2;

  if(leviKlik == true) digitalWrite(joystick[0], LOW);
  else digitalWrite(joystick[0], HIGH);
  if(y > treshold) digitalWrite(joystick[1], LOW);
  else digitalWrite(joystick[1], HIGH);
  if(y < -treshold) digitalWrite(joystick[2], LOW);
  else digitalWrite(joystick[2], HIGH);
  if(x > treshold) digitalWrite(joystick[3], LOW);
  else digitalWrite(joystick[3], HIGH);
  if(x < -treshold) digitalWrite(joystick[4], LOW);
  else digitalWrite(joystick[4], HIGH);
}
