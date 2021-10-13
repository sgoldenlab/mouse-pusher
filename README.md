# Mouse Pusher 

Mouse pusher is a complementary mechanical device for the med-pc operant boxes, to replace manual labor when propelling mice into the experiment arena.  Potentially, by freeing researcher from pushing multiple mice at the same time, the mouse pusher can improve efficiency and accuracy of the procedures and even reduce the audience effect on the mice. This design were tested in the aggression protocol at the Golden Lab UW.  

## Demonstration video 

https://user-images.githubusercontent.com/50497030/128563699-18b8701d-70c7-49fd-a3ca-df1fa9bf6b25.mp4



## Wiring diagram of linear rail

components list 
- Arduino uno
- L298N motor driver
- linear stage rail ( the one I used is https://www.amazon.com/Linear-Actuator-Stepper-Milling-Machine/dp/B07K7FQ245. You can replact it with other 100m linear stage rails)
- screws (based on your linear stage rail requirement) 
- 24V power adapter (for the stepper motor, might be different depends on the motor you have)
- 9V power adapter (for powering arduino separately) 
- jumper wires
- electrical tape



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

## Wiring connecting arduino and Med-PC

components：

- 24V to 5V Optocoupler ( I used 8 channel ones for every 6 of the wire set, you can buy any type of optocoupler that suits best for your project requirement)  
- 5V power adapter 
- wire
- electrical tape

we use optocoupler for the step down of the high voltage ttl signal from Med-PC to protect arduino from frying. 

## Code


### Arduino script

#### Operant box trial script 

  https://github.com/sgoldenlab/mouse-pusher/blob/522724d3c4da9a7dc0e854c799d4fd747f263456/Arduino%20Scripts/Trial_script.ino/Trial_script.ino.ino

  This script is for running the actual operant box trials, detailed explanation in the script file, might need small modification to fit your specific trials. 

#### Linear stage position adjustment script

  https://github.com/sgoldenlab/mouse-pusher/blob/522724d3c4da9a7dc0e854c799d4fd747f263456/Arduino%20Scripts/Position_adjustment_script.ino/Position_adjustment_script.ino.ino

  This script can be used to move the stage to the preferred starting position, or if stalling problem happens, can be used to do some quick testing for the specific reason for stalling

#### Testloop script 

  https://github.com/sgoldenlab/mouse-pusher/blob/522724d3c4da9a7dc0e854c799d4fd747f263456/Arduino%20Scripts/Testloop_script.ino/Testloop_script.ino.ino

  We used this script to test if the wired pusher set is stable before installing it on the opearnt box. This script is optional but we found it useful to prevent the hassel of fixing it after the set being attached to the opearnt box. 


### Med-PC code



```
```


## STL models

### Chamber Body 

![image](https://user-images.githubusercontent.com/50497030/137041128-a610d6ea-29f9-4f08-b11f-2caf876cdedc.png)

The chamber body would be the structure to contain the mice before they are pushed into the operant box, it can contain two mice at a time so the intruder mice can rotate and not getting thrown into the arean as frequently. 

### Pole

![image](https://user-images.githubusercontent.com/50497030/137041403-1e8ee3a2-63fe-48c1-8f98-4784bdcc3fb6.png)

The pole is attached to the linear stage, through screw in the four holes, the side with longer side being towards the back of the linear stage. Modification might be needed if the stage has different dimensions.

### Bottom 1 

![image](https://user-images.githubusercontent.com/50497030/137041483-8de43241-9a7e-4f55-adcf-a986cec620eb.png)

This is the first detachable bottom of the two, they can be fitted together into the gap at the bottom of the chamber 

### Bottom 2

![image](https://user-images.githubusercontent.com/50497030/137041558-44ffa38b-2391-4ea4-8b80-7dda22fa1aad.png)

This is the second detachable bottom of the two, they can be fitted together into the gap at the bottom of the chamber. We have designed the bottoms to be thinner and narrower than the gap of the chamber, but due to 3d printer's accuracy, it might still be hard to fit in or remove them. The little wedge on the second bottom can help you grip it better, and makes it easier to remove this bottome first. If hand strength not enough, please try a plier. If still not fitting correctly, some decrease in width and length might be needed. 

### Pusher plate 

![image](https://user-images.githubusercontent.com/50497030/137041666-0d07f604-e505-4729-899c-7101b521dd7d.png)

The pusher plate is going to be attached onto the pole, the side with shorter legs being the inward side. 



![image](https://user-images.githubusercontent.com/50497030/137041767-be8f6b51-c6a9-4284-8371-fbbd8bc764d5.png)

![image](https://user-images.githubusercontent.com/50497030/137041814-e37ff71f-e620-47d1-89ed-c13e351ff50f.png)




## Common problems



## Precautions

Turning off when not using, especially before closing operant box, turning of operant box first will lead to all boxes push forward because the voltage change by the optocoupler 
