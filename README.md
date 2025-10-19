🦾 Iron Man Mark III Gauntlet Control System

A gesture-based control system for a cosplay Mark III Iron Man gauntlet, integrating flex and pressure sensors with servo motors to control missile deployment and shield activation in real time.
Built using Arduino C++ and hobby-grade components.

--------------------------------------------------------------------------

✨ Features

🎯 Gesture recognition using flex and pressure sensors

🛡️ Shield activation through pressure sensor input

🚀 Missile deployment through flex sensor bending

🔐 Lock/unlock system to disable control for free hand movement

🧭 Simple calibration procedure for adapting to different users

------------------------------------------------------------------------

🧰 Tech Stack & Tools

Language: C/C++ (Arduino)

Microcontroller: Arduino Uno (or compatible)

Libraries: Servo.h

Sensors: Flex sensor, Force/Pressure sensor

Actuators: 3× SG90 servo motors (or equivalent)

IDE: Arduino IDE

--------------------------------------------------------------------------

🧪 Calibration Guide

Before use, calibrate the flex and pressure sensors to match your hand:

1.Open Serial Monitor (9600 baud).

2.Uncomment the calibration lines in sensor_reading() function.

3.Bend your finger and press the sensor as you would during use.

4.Note the printed sensor values.

5.Update the FLEX_THRESHOLD and PRESS_THRESHOLD constants in the code with your personal values.

---------------------------------------------------------------------------

🧠 How It Works

- Flex Sensor: When bent below the flex threshold, Servos 1 & 2 activate to simulate missile launch.

- Pressure Sensor: When pressed above the threshold, Servo 3 activates to deploy the shield.

- Lock Button: Toggles system ON/OFF to avoid accidental triggering.

- Loop: Continuously reads sensors and updates actuators in real time.

-----------------------------------------------------------------------------

🧑‍💻 Authors

TheWinterFox – Embedded programming, control system design

Samurai – System integration, concept, testing

------------------------------------------------------------------------------

📄 License

This project is released under the MIT License
.

---------------------------------------------------------------------------





