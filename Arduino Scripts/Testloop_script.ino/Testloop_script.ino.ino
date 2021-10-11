
#include<Stepper.h>
int Stepsperrev = 200;
Stepper Nema(Stepsperrev, 8,9,10,11);
//setup for stepper motor library and steps per revolution 




void setup() {
  // put your setup code here, to run once:​
}


void loop() {
    // put your main code here, to run repeatedly:
    
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  // turn arduino outputs to high before running stepper motor 
  
  Nema.setSpeed(550);
  Nema.step(Stepsperrev * 20);
  Nema.setSpeed(700);
  Nema.step(Stepsperrev * 83);
  // run the stage forward to the end of the rail
  
delay(5000);
// pause for 5 seconds 

  Nema.setSpeed(400);
  Nema.step(Stepsperrev * -20);
  Nema.setSpeed(550);
  Nema.step(Stepsperrev * -83);
  // run the stage back to starting position 
  
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  // turn arduino outputs to low after running stepper motor 
   
  
delay(10000);
// pause 10 seconds before run the loop again 
  }
