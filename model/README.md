# Facial Emotion Recognition Model

## Overview
A quick model building process was done in order to get an MVP Facial Emotion detector working quickly, since the main aim of this project was to showcase C++ skills, not ML or Python. This directory contains:
- *Facial Emotion Recognition Model - CNN.ipynb*, *Facial Emotion Recognition Model - Transfer.ipynb* Jupyter Notebooks where I prototyped and built the machine learning model
- *tensorflow_model.pb*: the protobuf file that contains the tensorflow graph and the model weights
- *haarcascade_frontalface_alt2.xml*: Haar Cascades model that was copied from the OpenCV library in "data/haarcascades/". Copied here so that it is easier to refer to the model path.


## Data
The data was sourced from the FER2013 Facial Expression Recognition dataset, which was initially presented as a Kaggle competition: https://www.kaggle.com/c/challenges-in-representation-learning-facial-expression-recognition-challenge/data. This dataset consists of 48x48 grayscale images of faces, each with one of 7 facial expressions (0=Angry, 1=Disgust, 2=Fear, 3=Happy, 4=Sad, 5=Surprise, 6=Neutral). The training set contained 28,709 images while the public and private test sets each contained 3,589 images. For my experiments I used the public test set as my validation set and the private test set as my testing set.

## Model
I tested 2 models for the FER2013 dataset:
- Transfer learning using ResNet50 architecture and ImageNet weights - 44% accuracy
- Convolutional Neural Network - 61% accuracy (potentially could train for more epochs as I wasn't overfitting much yet)

## Requirements
- tensorflow <= 1.15 (freezing the model graph does not work on tf v2.0)
