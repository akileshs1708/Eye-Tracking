# Eye Tracking
with Arduino and Ultrasonic Sensors

This computer organisation project implements a simple real-time eye tracking system using Arduino, ultrasonic sensors, and servo motors. The system tracks an object by measuring the distance from two ultrasonic sensors and adjusts the position of two servos to maintain visual contact with the object.

## Components

- **Arduino Nano Every**
- **2x HC-SR04 Ultrasonic Sensors**
- **2x SG90 Micro Servo Motors**
- **Breadboard (170 pins)**
- **Jumper wires**

## Hardware Setup

### Wiring

1. **Ultrasonic Sensors (HC-SR04)**:
   - **Sensor X**:
     - `Trig` pin connected to Arduino pin `2`
     - `Echo` pin connected to Arduino pin `3`
   - **Sensor Y**:
     - `Trig` pin connected to Arduino pin `5`
     - `Echo` pin connected to Arduino pin `6`
  
2. **Servo Motors**:
   - **Servo Left**:
     - Control pin connected to Arduino pin `8`
   - **Servo Right**:
     - Control pin connected to Arduino pin `10`

3. **Power Supply**: Ensure that your Arduino board is properly powered via USB.

### Circuit Diagram
For a simple circuit diagram, please refer to the schematic provided in the repository to visualize the connections.

## Software Setup

1. Install the **Arduino IDE** on your computer: [Download Arduino IDE](https://www.arduino.cc/en/software)
2. Open the `Arduino IDE` and write or upload the code provided in the project directory.
3. Select your Arduino board (Arduino Nano Every) and the correct COM port from the **Tools** menu in Arduino IDE.
4. Click on the **Upload** button to upload the code to the Arduino board.

## Code Overview

The Arduino code continuously measures the distances using the ultrasonic sensors (`HC-SR04`), maps these distances to servo angles, and adjusts the position of the servos (`SG90`). The servos follow the object by changing their orientation to keep the object within the field of view.

### Key Functions

1. **`measureDist(trigPin, echoPin)`**: This function triggers the ultrasonic sensor and calculates the distance in centimeters based on the sensor's response time.

2. **`servoControl(servoPin, angle)`**: This function controls the servo's position by mapping the angle to the pulse width required by the servo motor.

3. **`loop()`**: The main loop where distance readings are continuously taken from both ultrasonic sensors, and the servos' positions are adjusted accordingly.

### Code Customization
- **Distance Constraints**: Modify the `A` and `B` values to adjust the distance limits for each sensor.
  - `A` controls the X-axis distance (horizontal movement).
  - `B` controls the Y-axis distance (vertical movement).

- **Servo Range**: You can modify the `map()` function ranges to adjust how much the servos move based on the sensor data. By default, the servos move between 45° and 135° on the X-axis and from 40° to 0° on the Y-axis.

- **Servo Motors**: If you're using different servo models, adjust the pulse width values in the `servoControl()` function (currently set from 544 µs to 2400 µs).

## Usage

1. Place the ultrasonic sensors at appropriate positions so that they can detect the target object.
2. Power on your Arduino board.
3. The servos will begin tracking the object based on the measurements from the ultrasonic sensors.
4. Adjust the positioning of the servos and sensors to suit your tracking setup.
