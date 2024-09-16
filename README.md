 Self-Driving Car Using Machine Learning, Python, and Arduino

This repository contains the implementation of a self-driving car project utilizing Machine Learning (ML), Python, and Arduino. The project is aimed at creating an autonomous vehicle system that can detect its environment using a mobile camera and make decisions to navigate through obstacles.

 Project Overview

This self-driving car is built using:
- Machine Learning: For object detection and path planning.
- Python: For data processing, model training, and communication between components.
- Arduino: For controlling the physical movements of the car based on ML decisions.
- Mobile Camera: Used for real-time video feed to detect obstacles and make driving decisions.

The goal of this project was to build a miniature model that mimics real-world autonomous driving systems using accessible technologies.

 Features

- Camera-based Obstacle Detection: Uses the mobile camera feed along with ML algorithms to detect and classify objects in the car's path.
- Path Planning: Generates a safe path based on the car’s surroundings.
- Real-time Control: Arduino is used to control the motors and handle the car’s movement in real time.
- Data Processing: Python scripts handle data from the camera feed, process it using ML, and send commands to Arduino for navigation.

 Components

- Arduino Uno: For controlling the motors and receiving input from Python.
- Mobile Camera: For capturing real-time image feed and detecting obstacles.
- Machine Learning Model: Used to process input data from the camera and make decisions.
- Motor Driver: To manage the car’s speed and direction.
- Python Scripts: For ML model integration and decision-making logic.

How It Works

1. The mobile camera captures an image feed of the surroundings.
2. The ML model processes the image frames to detect obstacles and predict the best path.
3. The Python script communicates with the Arduino via serial to send movement instructions.
4. Arduino controls the motors to adjust the car's speed and direction accordingly.

 Future Improvements

- Implementing advanced computer vision techniques for more accurate detection.
- Improving path planning algorithms for more complex environments.
- Adding GPS-based navigation for outdoor environments.
 
Special thanks to the open-source community for the libraries and resources used in this project.
