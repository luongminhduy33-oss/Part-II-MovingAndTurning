# **Part-II-Moving-and-turning (Using encoders)**
# **II.1/ Straight movements**
***Microcontrollers*** (Arduino Nano, ESP32, STM32, ...) play a role as a brain of electronic devices. 
***A motor driver*** such as the L298N or DRV8833 controls the motors by receiving commands from the microcontroller.

The relationship is similar to how: 
- The **human brain** → sends signals
- Signals through the **nervous system** → to the muscles
- Which then **performs** movement

In robotics:
- **Microcontroller** → sends commands
- **Motor drivers** receives → power control
- **Motors** → physical movements

## **1. Motors**
Due to the competition's restrictions, only dual shifted DC motors are allowed.

<img width="400" height="300" alt="image" src="https://github.com/user-attachments/assets/b5c5ccf0-e64d-4f7f-b3f3-aa5afdfb4c3d" />

## **1.1 How a DC V1 motor works?**
- A DC motor operates on the principle of converting eletricical energy into mechanical energy through a magnetic field interaction.

<img width="400" height="300" alt="image" src="https://github.com/user-attachments/assets/048ae5a7-0a6e-47a2-9c97-5c60c6114a83" />

**Basic principle**
When the electric current flows through the coil:
1. A magnetic field is generated
2. The magnetic field interacts with the magnets
3. This creates a rotational force (Torque)


## **1.2 DC motors drawbacks**
Even two identical motors barely rotate at the same speed. 
## ***Solution - Real-time feedback (Using encoder or MPU6050)***
To move accurately, the robot needs to measure its movements constantly using sensors.

**A. Encoder (Counts wheel rotation - pulse):**
An encoder counts wheel rotations using pulses.

**Encoder provides:**
1. Distance travelled
2. Wheel speed
3. Difference between right and left wheels

**B. MPU6050 (Gives angular velocity)**
The MPU6050 contains a gyroscope and accelerometer.

**MPU6050 provides:** 
1. How fast you are rotating - angular velocity 
2. Maintains a straight heading - heading stabilization
3. Detects turning - rotation direction

# II.1.1/ Heading stabilization 
**Problem**
DC motors can't never rotate equally

## Solution - Real-Time heading correction
**A. Encoder difference**

Compare:
Difference = L - R

Where:
- L = Left encoder pulses  
- R = Right encoder pulses

If:
- L > R → Robot turning left
- R > L → Robot turning right
The controller compensates by adjusting motor speed

Example: 
- L > R:
  → Left - 5 (Pwm)
  → Right + 5 (Pwm)
- R > L:
  → Right - 5 (Pwm)
  → Left + 5 (Pwm)

Problem:
Wheel rotation stops working if pwm is too low (<125).

Solution:
Clamp the motors' speed with the minimum pwm is 130, the maximum is 145.

**Core ideal:**
Are the wheels rotating equally?

**B. Gyroscope stabilization**

Provides:
How far off the robot is from the exact targeted angle.

**Core ideal:**
Is the robot actually facing the correct direction?

# II.1.2/ Distance that micromouse has travelled 
This part is purely geometry. Using encoder pulses to convert -> distance

<img width="467" height="266" alt="image" src="https://github.com/user-attachments/assets/b9ce3a94-60f0-464c-a306-090527791930" />

**Core Ideal**
How far I am from the target right now **not** How many pulses do I need to move.

By counting pulses, we can estimate how far the robot has travelled.

## Proper calibration method
### Step 1 - Measure real movement
- Move the robot forward slowly
- Measure the travelled distance using a ruler
- Record encoder pulses (10-15)
For example: 12cm ≈ 88 pulses
Convert it into:

cm per pulse = 12 cm/90 pulses

***cm per pulse = 0.15 cm/pulse***

***Code***
  target_Pulses = desired_distance / cm_per_pulse

  current_Pulses = (left + right) / 2 //If the robot moves straight -> both similar in pulses -> average is accurate
  
  error = target_Pulses - current_Pulses

 
