# Smart Obstacle Detection & Collision Alert System

## Overview
An Arduino-based system to detect surrounding obstacles and provide proximity alerts using LEDs and a buzzer. Designed for integration in a car, it includes collision detection and communicates via Bluetooth.

## Components Used

### Sensors
- **MPU6050** - Detects sudden acceleration/deceleration (used for collision detection)
- **Ultrasonic Sensor** - Measures distance to nearby objects

### Actuators
- **LED** - Indicates proximity to obstacles
- **Buzzer** - Alerts in reverse mode with beeping rate based on proximity
- **Airbag Mechanism** - Simulated trigger on collision

### Communication
- **Bluetooth Module (HC-05)** - Sends data wirelessly

## Features
- **Obstacle Detection**: Lights LED based on object proximity.
- **Reverse Alert**: Buzzer beeps faster as distance reduces.
- **Collision Response**: Triggers airbag simulation upon impact.
- **Bluetooth Communication**: For monitoring and data logging.

## How It Works
1. Ultrasonic sensor detects distance to obstacles.
2. LED lights up at varying intensities based on proximity.
3. In reverse mode, buzzer beeps with increasing frequency as objects get closer.
4. MPU6050 detects collision; triggers airbag release.
5. Bluetooth module sends real-time data.

## Setup & Usage
Upload the Arduino code, connect the components, and power the system.
Code available in `code` folder
---
