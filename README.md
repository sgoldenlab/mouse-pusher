# Mouse Pusher 

Mouse pusher is a complementary mechanical device for the med-pc operant boxes, to replace manual labor when propelling mice into the experiment arena.  Potentially, by freeing researcher from pushing multiple mice at the same time, the mouse pusher can improve efficiency and accuracy of the procedures and even reduce the audience effect on the mice. This design were tested in the aggression protocol at the Golden Lab UW.  

### Demonstration video 

https://user-images.githubusercontent.com/50497030/128563699-18b8701d-70c7-49fd-a3ca-df1fa9bf6b25.mp4



1. wiring diagram of linear rail

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
int Stepsperrev = 200;
int motSpeed = 600;
Stepper Nema(Stepsperrev, 8,9,10,11);
int readPin = A3;
int V2 = 0 ;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Nema.setSpeed( motSpeed ) ;
}


void loop() {
  // put your main code here, to run repeatedly:
  V2 = analogRead(A3);
  
  if (V2 == 1023 || V2 == 0 ){
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  Serial.print(V2);
  
  }
  else {
   Serial.print(V2);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
  
    Nema.step(Stepsperrev * 103);
    delay(5000);
    Nema.step(Stepsperrev * -103);
   
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(170000);
  }    
  
  delay(2000);
}

```

Med-PC code


```
```


3. stl model explanation
4. warning: truning off when not using, especially before closing operant box (might cause pusheing when gate closed), secure linear rail 
