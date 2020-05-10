# Real-time Facial Emotion Recognition - CppND Capstone Project

This is the source code for a realtime facial recognition application, which will be submitted for the capstone project of the Udacity C++ Nanodegree Program. Creating this app will involve the following steps:
1. Build a deep learning model using Keras/Tensorflow in Python (try to make this quick since this is not a graded part of the project).
2. Capture video using the laptop webcam in real-time using OpenCV.
3. Use the face detector in OpenCV draw a bounding box around the face (region of interest).
4. Deploy model using Tensorflow C++ API to do model inference on the image in the bounding box.
5. Print the model prediction to the screen in real-time.

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

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./emotion_detector`.
