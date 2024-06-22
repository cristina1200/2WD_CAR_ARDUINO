#include <ControlMotor.h>

ControlMotor control(2,3,4,7,5,6); 

#include <Ultrasonic.h>
Ultrasonic sensor(9,8,30000); 

int mesurement_speed = 5;
long int distance = 0; 
int random_value = 0;

void setup() 
{ 
Serial.begin(9600);
 
} 
 
void loop() 
{ 
  control.Motor(150,1);
  distance=sensor.Ranging(CM);
  delay(mesurement_speed);
 

 Serial.print("No obstacle ");
 Serial.println(distance);
 Serial.print("Random ");
 Serial.println(random_value);

 random_value = random (2);
  while(distance<30){
  delay(mesurement_speed);
  control.Motor(0,1);
  distance = sensor.Ranging(CM);
  delay(1000);

  if(random_value==0){
 Serial.print("Distance ");
 Serial.println(distance);
 Serial.print("Random ");
 Serial.println(random_value);
 
  control.Motor(170,100);
  delay(400);}
  
  else if (random_value==1){
 Serial.print("Distance ");
 Serial.println(distance);
 Serial.print("Random ");
 Serial.println(random_value);
 
  control.Motor(170,-100);
  delay(400);}
  }
} 