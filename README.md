# Real-time Facial Emotion Recognition - CppND Capstone Project

## Introduction
This is the source code for a realtime facial emotion recognition application, which will be submitted for the capstone project of the Udacity C++ Nanodegree Program. Creating this app will involve the following steps:
1. Build a deep learning model using Keras/Tensorflow in Python. Freeze and save the model graph and weights as a .pb file.
2. Capture video using the laptop webcam in real-time using OpenCV.
3. Use the cascade face detector in OpenCV to detect a face and its location (for simplicity, one face will be detected at a time).
4. Draw a rectangular bounding box around the face (region of interest).
5. Preprocess the region of interest image to grayscale and resize to a 48x48 image, to match the input expected by the model.
6. Deploy model using the OpenCV Deep Neural Networks (dnn) module to do model inference on the image in the bounding box.
7. Display the video captured, along with the bounding box and the model prediction to the screen.

In order to make the code more efficient, the C++ code will be run in 2 threads. The 1st thread will consist of the video capture, face detection and drawing bounding box and video display, while the 2nd thread  will consist of preprocessing the image and model prediction. The result of the model prediction string will be fed back to the video display when it is ready. The c++ code structure is shown in the diagram below:
<img src="images/code_structure.png"/>

## Rubric Points Satisfied
1. 
2. 
3. 
4. 
5. 

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* OpenCV == 4.3.0 (other versions may work but they are untested)

## Basic Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./emotion_detector`.
