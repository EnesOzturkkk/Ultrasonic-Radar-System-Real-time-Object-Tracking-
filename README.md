# Arduino Ultrasonic Radar System
A fully functional, real-time Ultrasonic Radar System built with Arduino. This project utilizes an HC-SR04 ultrasonic sensor and an SG90 servo motor to scan a 180-degree field of view, detecting objects and triggering an alarm system.

🚀 Features
Dual-Scan Algorithm: Efficiently scans in both directions (0° to 180° and 180° to 0°) to double the refresh rate.
Real-time Monitoring: Streams precise distance and angle data to the Serial Monitor.
Proximity Alert: Triggers a buzzer and laser signal when an object enters the defined 30cm "danger zone."
Configurable Range: Detection threshold can be easily adjusted in the code for up to 4 meters.

🛠 Hardware Requirements
Microcontroller: Arduino Uno
Sensor: HC-SR04 Ultrasonic Distance Sensor
Actuator: SG90 Micro Servo
Feedback: Active Buzzer & Laser Module
Other: Breadboard, Jumper Wires, 5V Power Supply

🔌 Wiring Diagram
Component               Arduino 
PinHC-SR04 Trig         Pin 11
HC-SR04 Echo            Pin 12
SG90 Servo              Pin 9
Laser Module            Pin 8
Active Buzzer           Pin 7

💻 Software
The project uses the standard Servo.h library. The logic is based on a non-blocking sweep algorithm that calculates distance while the servo is in motion.

🦾 Installation
1-Clone this repository.
2-Open UltrasonicRadarSystem.ino in the Arduino IDE.
3-Connect your Arduino Uno.
4-Upload the code and open the Serial Monitor (Baud rate: 9600).

🎥 Demonstration
Watch the full project build and demo on my YouTube channel:[https://www.youtube.com/watch?v=Bq7ytcVUfIo&t=4s]
