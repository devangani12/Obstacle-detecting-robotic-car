🤖Obstacle Detecting Robotic Car : An Arduino-based autonomous robot that detects and avoids obstacles using ultrasonic sensors. Ideal for learning embedded systems and robotics.

🔧Components
- Arduino UNO
- Ultrasonic Sensor (HC-SR04)
- L298N Motor Driver
- BO Motors (x4)
- Wheels
- Battery Pack
- Jumper Wires

⚙️Working
The working of the obstacle avoiding robot is based on distance sensing using an ultrasonic sensor and decision-making by an Arduino UNO to control the robot’s motors through an L298N motor driver. 
🔸 1. Sensing the Distance:-
The ultrasonic sensor (HC-SR04) has two main parts: a trigger pin and an echo pin.
Arduino sends a pulse to the trigger pin which emits ultrasonic sound waves.
These waves bounce back from any obstacle and return to the sensor.
The time taken for this round trip is measured via the echo pin.
🔸 2. Calculating the Distance:-
The formula used:Distance (cm) = (Time × Speed of Sound) / 2.
Speed of sound in air = ~343 m/s (or 0.0343 cm/µs).
Arduino calculates this and gives the distance to the nearest obstacle in centimeters.
🔸 3. Decision Making:-
If the distance is greater than 20 cm, the path is clear → robot moves forward.
If the distance is less than 20 cm, an obstacle is detected → robot stops and turns (left/right based on code).
This simple logic allows the robot to autonomously navigate without crashing.
🔸 4. Motor Control via L298N:-
Arduino sends control signals to the L298N motor driver, which controls the BO motors connected to the wheels.
Depending on the signal combination (HIGH or LOW on input pins), the motors move forward, backward, or turn.
🔸 5. Final Behavior:-
The robot continuously repeats this loop:
Sense distance.
Calculate and compare.
Move forward or turn.
This gives the robot a basic autonomous obstacle avoiding behavior.

🔌Circuit Diagram
![circuit diagram of model](https://github.com/user-attachments/assets/465817af-fd94-49b0-bdd2-8e9827bd0f65)


Model images 
-![side view of model](https://github.com/user-attachments/assets/a7b46242-6c35-4f6a-af3c-0760c1ade7ed)
-![front view of model](https://github.com/user-attachments/assets/67934df6-fda3-4c69-8fab-b3296b2a6e8a)
-![top view and connections of model](https://github.com/user-attachments/assets/4a455923-a539-448e-b525-7345a989e50e)


🙋‍♀️Created By
**Devangani Singh**  
[LinkedIn](https://www.linkedin.com/in/devangani-singh-b413a42b1)  
devangani1223@gmail.com
