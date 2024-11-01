## Distance Sensing and Feedback System
This is an Arduino-based project that uses an ultrasonic sensor to measure the distance to an object and provides both visual and audio feedback based on the measured distance.

## Features
Ultrasonic Sensor: The project utilizes an ultrasonic sensor to measure the distance to an object.
Distance Calculation: The duration of the ultrasonic pulse is measured and used to calculate the distance in centimeters.
Distance Thresholds: The project defines three distance thresholds: 5 cm, 10 cm, and 15 cm.
LED Indicators: Three LEDs (red, yellow, and green) indicate different distance ranges:
Red LED: 0-5 cm
Yellow LED: 5-10 cm
Green LED: 10-15 cm
Buzzer Feedback: A buzzer emits different sound patterns based on the distance range to provide auditory feedback.
Faster sound for closer distances
Slower sound for farther distances
Serial Communication: The measured distance is printed to the serial monitor for debugging and monitoring purposes.
## Hardware Required
Arduino board (e.g., Arduino Uno, Arduino Nano)
HC-SR04 ultrasonic sensor
3 LEDs (red, yellow, green)
1 buzzer
Jumper wires
Breadboard (optional)
## Circuit Diagram
[![Circuit Diagram][]](https://projecthub.arduino.cc/Krepak/ultrasonic-security-system-a6ea3a)

## Software Setup
Download and install the Arduino IDE from the official website: https://www.arduino.cc/en/software
Open the Arduino IDE and create a new sketch.
Copy the provided code (sketch_dec21b.ino) into the sketch.
Connect the hardware components as per the circuit diagram.
Upload the sketch to your Arduino board.
## Usage
Power on the Arduino board.
The system will start detecting the distance to an object in front of the ultrasonic sensor.
The LEDs and buzzer will provide feedback based on the measured distance:
Red LED and fast buzzer sound: 0-5 cm
Yellow LED and medium buzzer sound: 5-10 cm - Green LED and slow buzzer sound: 10-15 cm
The measured distance will be printed to the serial monitor.
## Customization
You can modify the code to change the distance thresholds, the LED and buzzer behavior, or add additional features as per your requirements.

## License
This project is licensed under the MIT License.
