# Mouse Pusher 

Mouse pusher is a complementary mechanical device for the med-pc operant boxes, to replace manual labor when propelling mice into the experiment arena.  Potentially, by freeing researcher from pushing multiple mice at the same time, the mouse pusher can improve efficiency and accuracy of the procedures and even reduce the audience effect on the mice. This design were tested in the aggression protocol at the Golden Lab UW.  

## Demonstration video 

https://user-images.githubusercontent.com/50497030/128563699-18b8701d-70c7-49fd-a3ca-df1fa9bf6b25.mp4



## Wiring diagram of linear rail

For each mouse pusher, we need the following components below:

#### Components list 
- Arduino Uno
- L298N Motor Driver
- [Linear Stage Rail](https://www.amazon.com/Linear-Actuator-Stepper-Milling-Machine/dp/B07K7FQ245)
- Screws (based on your linear stage rail requirement) 
- 24V Power Adapter (for the stepper motor, might be different depends on the motor you have)
- 9V Power Adapter (for powering arduino separately) 
- Jumper wires
- Electrical tape



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

### Step by Step assembling instruction 

Step 1: braid the wires from the linear stage rail 

<img src="https://user-images.githubusercontent.com/50497030/138615670-2cf6880b-ed0a-4ae4-b546-1769269f8538.jpg" width="400">

Step 2: wrap electrical tape around the wire for protection

<img src="https://user-images.githubusercontent.com/50497030/138615680-c3180e80-be2a-4978-aebc-22f3c6b40e58.jpg" width="400">

step 3: take out two sets of two male to male jumper wires, and a set of four male to female jumper wires.

<img src="https://user-images.githubusercontent.com/50497030/138615685-8e5d5677-6a1e-4e28-a62e-01c958479217.jpg" width="400">

step 4: wrap electrical tapes around jumper wires, we color coded them to distinguish different sets.

<img src="https://user-images.githubusercontent.com/50497030/138615693-9c2e86de-b301-4c00-8ed2-e4164efcf623.jpg" width="400">

step 5: connect wires to l298N motor driver according to the table above 

<img src="https://user-images.githubusercontent.com/50497030/138615701-b737ff1d-0278-413b-b7e6-509923d78273.jpg" width="400">

step 6: connect wires to arduino according to the table above

<img src="https://user-images.githubusercontent.com/50497030/138615715-e3d7953f-d147-4428-8d92-190f552e6aaa.jpg" width="400">

step 7: connect the wire from 12V+ port from L298N to the positive on the adapter, and the ground to the negative on the adapter.

<img src="https://user-images.githubusercontent.com/50497030/138615719-f7693209-9a56-4a2f-9bb9-c5d65410ab39.jpg" width="400">

step 8: plug in 24V to L298N power adapter and 9V to arduino 


## Wiring connecting arduino and Med-PC

#### Components：

- 24V to 5V Optocoupler ( I used 8 channel ones for every 6 of the wire set, you can buy any type of optocoupler that suits best for your project requirement)  
- 5V power adapter 
- Wire
- Electrical tape

Optocoupler is used to step down the high voltage ttl signal from Med-PC to protect Arduino from frying. 

## Code


### Arduino script

#### Operant box trial script 

  [Click here for Operant Box Trial Script](https://github.com/sgoldenlab/mouse-pusher/blob/522724d3c4da9a7dc0e854c799d4fd747f263456/Arduino%20Scripts/Trial_script.ino/Trial_script.ino.ino)

  This script is for running the actual operant box trials, detailed explanation in the script file, might need small modification to fit your specific trials. 

#### Linear stage position adjustment script

  [Click here for Linear stage position adjustment script](https://github.com/sgoldenlab/mouse-pusher/blob/522724d3c4da9a7dc0e854c799d4fd747f263456/Arduino%20Scripts/Position_adjustment_script.ino/Position_adjustment_script.ino.ino)

  This script can be used to move the stage to the preferred starting position, or if stalling problem happens, can be used to do some quick testing for the specific reason for stalling

#### Testloop script 

  [Click here for testloop script](https://github.com/sgoldenlab/mouse-pusher/blob/522724d3c4da9a7dc0e854c799d4fd747f263456/Arduino%20Scripts/Testloop_script.ino/Testloop_script.ino.ino)

  We use this script to test if the wired pusher set is stable before installing it on the opearnt box. This script is optional but we found it useful to prevent the hassel of fixing it after the set being attached to the opearnt box. 


### Med-PC code

[Click Here for example for the Med_PC code](https://github.com/sgoldenlab/mouse-pusher/blob/7db21a7be5d829b1ad788d06850c045fe5f82429/MedPc%20code.MPC)

The code above is the Medpc script we used for self-administration aggression study, on the foundation of the original script,
We added ^Pusher = 14 (or any open output number you have) to Outputs sections,
then at the codes where you command for output to open the door, we added ON ^Pusher
Same where you command for output to close the door, we added OFF ^Pusher

Here are the examples clipped from the script above: 

![image](https://user-images.githubusercontent.com/50497030/137405463-d89999f7-9f0e-4cd6-96c3-753f43006969.png)

![image](https://user-images.githubusercontent.com/50497030/137405454-39b47aeb-d3a6-4b80-a053-284fa0f7035f.png)




## STL Models

[Click here to see display model for all components](https://github.com/sgoldenlab/mouse-pusher/blob/f5dbb41cf96dbcc75a5999b4762720fb7c1067de/STL%20files/Display.stl)

### [Chamber Body](https://github.com/sgoldenlab/mouse-pusher/blob/b585bb12850828008785d5a96545670da8c36cad/STL%20files/chamber.stl) 

![image](https://user-images.githubusercontent.com/50497030/137041128-a610d6ea-29f9-4f08-b11f-2caf876cdedc.png)

The chamber body would be the structure to contain the mice before they are pushed into the operant box, it can contain two mice at a time so the intruder mice can rotate and not getting thrown into the arean as frequently. 

### [Pole](https://github.com/sgoldenlab/mouse-pusher/blob/b585bb12850828008785d5a96545670da8c36cad/STL%20files/pole.stl)

![image](https://user-images.githubusercontent.com/50497030/137041403-1e8ee3a2-63fe-48c1-8f98-4784bdcc3fb6.png)

The pole is attached to the linear stage, through screw in the four holes, the side with longer side being towards the back of the linear stage. Modification might be needed if the stage has different dimensions.

### [Bottom 1](https://github.com/sgoldenlab/mouse-pusher/blob/b585bb12850828008785d5a96545670da8c36cad/STL%20files/bottom1.stl) 

![image](https://user-images.githubusercontent.com/50497030/137041483-8de43241-9a7e-4f55-adcf-a986cec620eb.png)

This is the first detachable bottom of the two, they can be fitted together into the gap at the bottom of the chamber 

### [Bottom 2](https://github.com/sgoldenlab/mouse-pusher/blob/b585bb12850828008785d5a96545670da8c36cad/STL%20files/bottoms2.stl)

![image](https://user-images.githubusercontent.com/50497030/137041558-44ffa38b-2391-4ea4-8b80-7dda22fa1aad.png)

This is the second detachable bottom of the two, they can be fitted together into the gap at the bottom of the chamber. We have designed the bottoms to be thinner and narrower than the gap of the chamber, but due to 3d printer's accuracy, it might still be hard to fit in or remove them. The little wedge on the second bottom can help you grip it better, and makes it easier to remove this bottome first. If hand strength not enough, please try a plier. If still not fitting correctly, some decrease in width and length might be needed. 

### [Pusher Plate](https://github.com/sgoldenlab/mouse-pusher/blob/b585bb12850828008785d5a96545670da8c36cad/STL%20files/pusherplate.stl) 

![image](https://user-images.githubusercontent.com/50497030/137041666-0d07f604-e505-4729-899c-7101b521dd7d.png)

The pusher plate is going to be attached onto the pole, the side with shorter legs being the inward side. 

### [Supporting Foundation](https://github.com/sgoldenlab/mouse-pusher/blob/b585bb12850828008785d5a96545670da8c36cad/STL%20files/supportU.stl)

![image](https://user-images.githubusercontent.com/50497030/137041767-be8f6b51-c6a9-4284-8371-fbbd8bc764d5.png)

This structure is being attached to the operant box under the chamber. the vertical thin flat surface can be fit in the same gap we use to attach the chamber body. the supporting foundation would make all the chamber body be on the same height and restrict unnecessary movement of the linear rail. Depends on the stability of your operant box, the support foundation might still be able to move around a lot, you can use tape to secure the side to the operant box. (If linear rail not the same dimensions, modification would be needed)

### [Rotate Block](https://github.com/sgoldenlab/mouse-pusher/blob/b585bb12850828008785d5a96545670da8c36cad/STL%20files/rotate.stl)

![image](https://user-images.githubusercontent.com/50497030/137041814-e37ff71f-e620-47d1-89ed-c13e351ff50f.png)

The rotate block is a 2 piece structure that would be fitted together through the round hole on the chamber body, when putting down after the divider is in, it would prevent the divider being moved out by the mice. 

### [Divider](https://github.com/sgoldenlab/mouse-pusher/blob/b585bb12850828008785d5a96545670da8c36cad/STL%20files/Divider.stl) 




## Common problems

1. Linear stage rail moves, causing the pusher plate or pole getting stuck by the chamber or other structure around the operant box. 

Solution: if stuck in the middle and not returning to the start position, use position adjustment script to return the stage back into starting position, and check for broken components, replace if needed. 

2. Not moving after wiring, often along with strange noise 

Solution: recheck all wiring to see if they are all in place, if they are, check if the right voltage of power adapted is connected. If still not solved, check the voltage reading from your mouse pusher script, if the voltage doesn't change to 1023 when you open output 14, it means there is no connection between arduino and medpc, you need to change wire or replug it. 

## Precautions

Turning off when not using, especially before closing operant box, turning of operant box first will lead to all boxes push forward because the voltage change by the optocoupler 

Our advice is to have some backup parts because before everything is properly installed and stablized, it might be very easy to break thin parts like poles and rotate block. 
