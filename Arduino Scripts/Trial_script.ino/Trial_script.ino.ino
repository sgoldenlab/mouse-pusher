#include<Stepper.h>  
// load in library for stepper motor 

int Stepsperrev = 200;
// set up steps per revolution, speed, pin number for stepper motor,change this to fit the number of steps per revolution for your motor

Stepper Nema(Stepsperrev, 8,9,10,11);
// initialize the stepper library on pins 8 through 11

int V2;
// create a Value for medPC input

void setup() {
// put your setup code here, to run once:

  Serial.begin(9600);
  // set up for printing anolog value 
  
}

void loop() {
// put your main code here, to run repeatedly:  
  
  V2 = analogRead(A3);
  // read pin A3 for voltage of the signal
  
  if (V2 <1020){
  // when not receving signal from medpc, anolog valus remains low, run the following code to stay at starting position 
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  // set the outputs from arduino to low when not using the stepper motor 
  
  Serial.print(V2);
  //reading from the anolog pin, useful for detecting problems 
  
  }

   else {
  // when anolog value high from receiving Medpc signal, run following code to run stepper motor forward and back
   
   Serial.print(V2);
   
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    // set the outputs from arduino to high when using the stepper motor 

    
  Nema.setSpeed(550);
  //set the value of the speed,the range of speed is 0 to 1000, you can adjust yourself, to prevent stepper motor stalling we use a lower speed first then switch to a higher speed.
  
  Nema.step(Stepsperrev * 20);
  Nema.setSpeed(700);
  Nema.step(Stepsperrev * 83);
  // the linear rail we used has a length of 103 full revolutions, you can test and change the number of revolutions to fit the rail you use. 
   
    delay(10000);
    // stepper motor stops for 10 seconds before moving back to starting position
   
  Nema.setSpeed(400);
  Nema.step(Stepsperrev * -20);
  Nema.setSpeed(550);
  Nema.step(Stepsperrev * -83);
  // step 103 steps in opposite direction, moving stage back to starting position 
   
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }    
  
  delay(2000);
  // pause 2 seconds before run the loop again
}
