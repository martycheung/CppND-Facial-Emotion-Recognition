#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <algorithm>
#include <mutex>

#include "FaceDetector.h"
#include "Image.h"
#include "Model.h"

// Update this with the path to your opencv directory
const std::string FACE_DETECTOR_MODEL_PATH = "../model/haarcascade_frontalface_alt2.xml";
const std::string TENSORFLOW_MODEL_PATH = "../model/tensorflow_model.pb";
const std::string APP_NAME = "Real-Time Facial Emotion Recognition";

int main()
{
    // Initialise video frame that will be read from the camera
    cv::Mat frame;
    // Initialise all the required objects
    Model model(TENSORFLOW_MODEL_PATH);
    FaceDetector face_detector;
    Image image_and_ROI;

    // Initialise video capture object with default camera
    cv::VideoCapture cap(0);	
    //create a window with the window name
    cv::namedWindow(APP_NAME);

    // Main Program Loop    
    while (true)
    {
        // read a new frame from video 
        bool bSuccess = cap.read(frame); 

        // break the while loop if the frames cannot be captured
        if (bSuccess == false) 
        {
            std::cout << "Video camera is disconnected. Stopping the program" << std::endl;
            std::cin.get(); //Wait for any key press
            break;
        }

        //Run Face Detection and draw bounding box
        face_detector.detectFace(frame);

        // Draw bounding box to frame
        image_and_ROI = face_detector.drawBoundingBoxOnFrame(frame);

        cv::Mat roi_image = image_and_ROI.getROI();
    
        if (!roi_image.empty()) {
            // Preprocess image ready for model
            image_and_ROI.preprocessROI();
            // Make Prediction
            std::string emotion_prediction = model.predict(image_and_ROI);
            // Add prediction text to the output video frame
            image_and_ROI = face_detector.printPredictionTextToFrame(image_and_ROI, emotion_prediction);
        }

        cv::Mat output_frame = image_and_ROI.getFrame();

        if (!output_frame.empty()) {
            // Display the video frame to the window
            imshow (APP_NAME, output_frame);
        } else {
            // if the output frame is empty (ie. the facedetector didn't detect anything), just display the original video capture
            imshow (APP_NAME, frame);
        }

        // wait for for 10 ms until any key is pressed.  
        // if the 'Esc' key is pressed, break the program loop
        if (cv::waitKey(100) == 27)
        {
            std::cout << "Esc key is pressed by user. Stopping the program" << std::endl;
            break;
        }

    }
    
    return 0;

}