# embedded_factory
**Conveyor Belt System with Raspberry Pi Pico:** *Refer to Project Report.pdf for better understanding.*

## Overview
This project involves a conveyor belt system controlled by a Raspberry Pi Pico microcontroller. The conveyor belt is powered by a synchronous motor that moves three cylinders and a belt. The system includes multiple sensors and an LCD display for monitoring the conveyor belt's status. The project incorporates the use of:

- **Relay**: Controls the 220V power to the motor (5V control from the Raspberry Pi Pico via a level shifter).
- **Servo Motor**: Sweeps objects off the conveyor when they are detected to be too close.
- **Sensors**:
  - **Touch Sensor**: Starts the system.
  - **IR Sensor**: Senses objects on the conveyor and counts them.
  - **Ultrasonic Sensor**: Measures the distance of objects and triggers the servo when an object is too close.
- **LCD Display**: Displays the count of objects and the current status of the motor (on/off).

## Hardware Components
- **Raspberry Pi Pico**: Microcontroller to control the entire system.
- **Synchronous Motor**: Moves the three cylinders and the conveyor belt.
- **Relay Module**: Switches the 220V power to the motor using a 5V control signal from the Raspberry Pi Pico.
- **Level Shifter**: Adjusts the 3.3V logic from the Raspberry Pi Pico to 5V to control the relay.
- **Servo Motor**: Moves objects off the conveyor when they are detected to be too close.
- **Touch Sensor**: Used to start or stop the conveyor belt system.
- **IR Sensor**: Senses objects on the conveyor and counts them.
- **Ultrasonic Sensor**: Measures the distance to objects on the conveyor and triggers the servo when the object is too close.
- **LCD Display**: Shows the count of objects on the conveyor and displays the current status of the motor.

## Features
- **Motor Control**: The motor can be turned on and off using the touch sensor.
- **Object Counting**: The IR sensor detects objects passing over it and updates the object count.
- **Object Sweeping**: The ultrasonic sensor detects the distance of objects and commands the servo motor to sweep objects off the conveyor if they are too close.
- **LCD Display**: Continuously displays the current object count and the motor status (on/off).

## Circuit Diagram
The hardware setup includes connections for the Raspberry Pi Pico to the relay, sensors, servo motor, and LCD display. Please refer to the provided circuit diagram for the detailed wiring.

## Software
The software running on the Raspberry Pi Pico is responsible for managing the sensors, controlling the relay and motors, and updating the LCD display.

### GPIO Pin Configuration:
- **Relay**: Connected to a GPIO pin through a level shifter.
- **Touch Sensor**: Used to start and stop the system.
- **IR Sensor**: Used to count objects.
- **Ultrasonic Sensor**: Measures the distance to objects.
- **Servo Motor**: Moves objects off the conveyor when too close.
- **LCD Display**: Displays the object count and motor status.

## Installation
1. Download and install the necessary software tools for Raspberry Pi Pico (e.g., Thonny or another IDE for Python development).
2. Clone or upload the project files to your Raspberry Pi Pico.
3. Connect the hardware components according to the circuit diagram.
4. Power the Raspberry Pi Pico and the external 220V power source for the motor.
5. Run the code to control the system.

## Code
The project utilizes C programming language and standard libraries to control the GPIO pins on the Raspberry Pi Pico. The code handles:
- Initializing and reading sensor values.
- Turning the motor on/off via the relay.
- Detecting objects using the IR and ultrasonic sensors.
- Updating the LCD display with the current motor status and object count.
- Sweeping objects off the conveyor using the servo motor.

## Usage
- **Start the system**: Press the touch sensor to turn the system on.
- **Count objects**: The IR sensor will count objects passing over it.
- **Sweep objects**: If the ultrasonic sensor detects an object too close, the servo motor will activate and sweep the object off the conveyor.
- **Stop the system**: Press the touch sensor again to stop the motor.

## Troubleshooting
- **Motor not starting**: Ensure the relay is properly connected and the level shifter is functioning.
- **Object count not updating**: Check the wiring and positioning of the IR sensor.
- **Servo motor not sweeping**: Verify the distance threshold set for the ultrasonic sensor and ensure the servo motor is powered correctly.

## Future Improvements
- Add more sensors for enhanced object detection.
- Implement a more advanced algorithm for controlling the conveyor speed.
- Add remote control capabilities for the system.

## License
This project is open-source and released under the MIT License.
