# Mouse Pusher
Mouse pusher

Mouse pusher is a complementary mechanical device for the med-pc operant boxes, to replace manual labor when propelling mice into the experiment arena.  Potentially, by freeing researcher from pushing multiple mice at the same time, the mouse pusher can improve efficiency and accuracy of the procedures and even reduce the audience effect on the mice. This design were tested in the aggression protocol at the Golden Lab UW.  


1. wiring diagram of linear rail

components list 
- Arduino uno
- L298N motor driver
- Jumper wires
- linear stage rail ( the one I used is https://www.amazon.com/Linear-Actuator-Stepper-Milling-Machine/dp/B07K7FQ245. You can replact it with other 100m linear stage rails)
- screws (based on your linear stage rail requirement) 


![download](https://user-images.githubusercontent.com/50497030/128560163-14e39093-8887-4fcd-acfa-9625174d9f88.jpeg)
![L298N-Motor-Driver-Module-Pinout](https://user-images.githubusercontent.com/50497030/128560178-6c45ff88-263f-42a5-8d72-34e5c1ec1af2.png)


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



2. arduino and med-pc code 


3. stl model explanation
4. warning: truning off when not using, especially before closing operant box (might cause pusheing when gate closed), secure linear rail 
