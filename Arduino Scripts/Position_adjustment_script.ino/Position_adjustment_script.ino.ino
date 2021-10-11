#include<Stepper.h>  
// load in library for stepper motor 

int Stepsperrev = 200;
// set up steps per revolution, speed, pin number for stepper motor,change this to fit the number of steps per revolution for your motor

Stepper Nema(Stepsperrev, 8,9,10,11);
// initialize the stepper library on pins 8 through 11

void setup() {
// put your setup code here, to run once:

  Nema.setSpeed(500);
  // set motor speed to a moderate value
 
  Nema.step(Stepsperrev * # );
  // put the number you want in place of the "#", run stepper motor forward or backward (add - in front of number if wants to run backward)   
 
}


void loop() {
  // put your main code here, to run repeatedly:

} 
