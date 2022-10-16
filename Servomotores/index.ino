#include <Servo.h>

int pos = 0;
int luz = 0;
int luz_a = 0;
int sobe = 0;


Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);
  Serial.begin(9600);
  luz = analogRead(A5);
  sobe = 1;
}

void loop()
{
  if(sobe){
     pos+=5;
     if(pos>=175){
      pos = 180;
    }
    servo_9.write(pos);
    delay(50);
    luz_a = analogRead(A5);
    Serial.println(luz_a);
    Serial.println(pos);
   
    if (luz_a < luz){
      luz = luz_a;
      sobe = 0;
    }
  }else {
    pos -=5;
    if(pos <=0){
      pos = 0;
    }
    servo_9.write(pos);
    delay(50);
    luz_a = analogRead(A5);
    Serial.println(luz_a);
    Serial.println(pos);
    
    if(luz_a > luz){
      luz = luz_a;
      sobe = 1;
    }
  }
      
  
  delay(100);
}