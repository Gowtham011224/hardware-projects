# Distance Sensing Using Ultrasonic Sensor

## Overview
This project involves designing and implementing a system that detects the distance of an object using an ultrasonic sensor and an Arduino Uno. The system triggers LEDs and a buzzer based on the distance detected, providing a visual and audible indication of proximity.

## Project Details

### Aim
To design and implement a system that detects the distance from an object using an Arduino Uno.

### Objective
1. Sense the distance of objects from a point using an ultrasonic sensor.
2. Trigger respective LEDs when an object is detected within given ranges.
3. Create an efficient and reliable proximity detection system.

### Principle
The system operates by emitting an ultrasonic pulse at 40 kHz. If the pulse encounters an obstacle, it bounces back to the sensor. The time taken for the pulse to return is measured and, using the speed of sound, the distance is calculated.

### Apparatus Required
- **Resistors**: 3 (150 - 330 Ω)
- **Buzzer**: 1
- **LED Bulbs**: 3 (Red, Yellow, Green)
- **Arduino Uno**: 1
- **Ultrasonic Sensor (HC-SR04)**: 1 (Range: 2-400 cm)
- **Breadboard**: 1
- **Connecting Wires**: A bunch

### Circuit Diagram
Refer to the `circuit_diagram.png` file in this repository for the complete circuit diagram.

### Working
1. **Hardware Connections:**
   - Connect the ultrasonic sensor's VCC to 5V on the Arduino, GND to GND, trigPin to pin 7, and echoPin to pin 8.
   - Connect LEDs to pins 4, 2, and 3 with appropriate resistors.
   - Connect the buzzer's positive terminal to pin 6 and the negative terminal to GND.
   
2. **Assembling Steps:**
   - Make the connections as described above.
   - Power up the Arduino and upload the provided code (`distance_sensor.ino`).
   - The system will measure distance and trigger LEDs and the buzzer based on the detected distance.

### Code
The project code can be found in the `distance_sensor.ino` file in this repository.

### Testing
To test the system:
1. Power on the Arduino.
2. Place an object at different distances from the ultrasonic sensor.
3. Observe the LEDs and the buzzer respond according to the distance.

### Challenges and Considerations
- **Sensor Accuracy**: Environmental factors like temperature, humidity, and air pressure can affect accuracy.
- **Interference**: Ensure minimal electronic and acoustic interference.
- **Power Supply**: Use a stable power source to avoid unreliable operation.

## Conclusion
This project successfully implements distance sensing using an Arduino Uno and ultrasonic sensor. It serves as an effective method for proximity detection with potential for further enhancements.

## References
1. [HowToMechatronics - Ultrasonic Sensor Tutorial](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)
2. [GeeksforGeeks - Distance Measurement using Ultrasonic Sensor and Arduino](https://www.geeksforgeeks.org/distance-measurement-using-ultrasonic-sensor-and-arduino/)
3. [Hackster.io - Controlling LEDs using Ultrasonic Distance Sensor](https://www.hackster.io/blackpanda856/controlling-led-s-using-ultrasonic-distance-sensor-19f38f)

## Author
Gowtham Rajasekaran - 2022506084  
Madras Institute of Technology, Chennai
