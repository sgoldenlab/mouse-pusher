# Mouse Pusher 

Mouse pusher is a complementary mechanical device for the med-pc operant boxes, to replace manual labor when propelling mice into the experiment arena.  Potentially, by freeing researcher from pushing multiple mice at the same time, the mouse pusher can improve efficiency and accuracy of the procedures and even reduce the audience effect on the mice. This design were tested in the aggression protocol at the Golden Lab UW.  

### Demonstration video 

https://user-images.githubusercontent.com/50497030/128563699-18b8701d-70c7-49fd-a3ca-df1fa9bf6b25.mp4



### wiring diagram of linear rail

components list 
- Arduino uno
- L298N motor driver
- Jumper wires
- linear stage rail ( the one I used is https://www.amazon.com/Linear-Actuator-Stepper-Milling-Machine/dp/B07K7FQ245. You can replact it with other 100m linear stage rails)
- screws (based on your linear stage rail requirement) 


<img src="https://user-images.githubusercontent.com/50497030/128560163-14e39093-8887-4fcd-acfa-9625174d9f88.jpeg" width="500" height="200">

<img src="https://user-images.githubusercontent.com/50497030/128561183-06ac6fb2-cab5-46e3-85cc-d66e5610e60a.png" width="500" height="350">




| Pin Name    | Description |
| ------------- | ------------- |
| OUT1 & OUT2  | Output pins of Motor A (A+ to OUT1, A- to OUT2 |
| OUT3 & OUT4  | Output pins of Motor B (B= to OUT3, B- to OUT2 |
| 12V / VCC    | power supply input, if > 12V DC, remove 12V jumper (black jumper in front of the input)|
| 5V | 5V pin on Arduino |
| GND | Ground pin |
| IN1 | pin 8 |
| IN2 | pin 9 |
| IN3 | pin 10 |
| IN4 | pin 11 |



2. Code


Arduino code
```
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

```

Med-PC code


```
```


3. stl model explanation
4. warning: truning off when not using, especially before closing operant box (might cause pusheing when gate closed), secure linear rail 
