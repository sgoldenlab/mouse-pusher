# Mouse Pusher
Mouse pusher

Mouse pusher is a complementary mechanical device for the med-pc operant boxes, to replace manual labor when propelling mice into the experiment arena.  Potentially, by freeing researcher from pushing multiple mice at the same time, the mouse pusher can improve efficiency and accuracy of the procedures and even reduce the audience effect on the mice. This design were tested in the aggression protocol at the Golden Lab UW.  


1. wiring diagram of lineaar rail

components list 
- Arduino uno
- L298N motor driver
- Jumper wires
- linear stage rail ( the one I used is https://www.amazon.com/Linear-Actuator-Stepper-Milling-Machine/dp/B07K7FQ245. You can replact it with other 100m linear stage rails)
- screws (based on your linear stage rail requirement) 

wiring disgram

| Pin Name    | Description |
| ------------- | ------------- |
| OUT1 & OUT2  | Output pins of Motor A (A+ to OUT1, A- to OUT2 |
| OUT3 & OUT4  | Output pins of Motor B (B= to OUT3, B- to OUT2 |
| 12V          | power supply voltage, if > 12V DC, remove 12V jumper (black jumper in front of the input)|

![L298N-Module-Pinout](https://user-images.githubusercontent.com/50497030/128436964-1dd0a23a-eccd-4c7c-91b6-6dd6512e6472.jpg)

![Bipolar-Stepper-L298N](https://user-images.githubusercontent.com/50497030/128436555-d7a2dc30-2050-4410-845c-7aba44faf7d3.jpg)


2. arduino and med-pc code  
3. stl model explanation
4. warning: truning off when not using, especially before closing operant box (might cause pusheing when gate closed), secure linear rail 
