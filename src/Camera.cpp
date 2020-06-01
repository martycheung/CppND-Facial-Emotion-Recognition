#include <opencv2/opencv.hpp>
#include <iostream>
#include "Camera.h"
#include "Model.h"

cv::VideoCapture cap(0);		// The openCV camera object...

Camera::Camera(const std::string& window_name, Model& model) : window_name(window_name), model(model) {

    frameWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    frameHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    std::cout << "Resolution of the video : " << frameWidth << " x " << frameHeight << std::endl;

    //create a window with the window name
    cv::namedWindow(window_name); 
    
}

void Camera::displayVideo() {

    while (true)
    {
        bool bSuccess = cap.read(frame); // read a new frame from video 
        //Breaking the while loop if the frames cannot be captured
        if (bSuccess == false) 
        {
            std::cout << "Video camera is disconnected" << std::endl;
            std::cin.get(); //Wait for any key press
            break;
        }

        //Run Face Detection and draw bounding box
        image_and_ROI = detector.detectFaceAndDrawRoi( frame);

        cv::Mat roi_image = image_and_ROI.getROI();

        if (roi_image.total()>0 && roi_image.total()>0) {
            // Preprocess image ready for model
            image_and_ROI.preprocessROI();
            // Make Prediction
            std::string emotion_prediction = model.predict(image_and_ROI);

            image_and_ROI = detector.addPredictionTexttoFrame(image_and_ROI, emotion_prediction);
        }

        cv::Mat video_frame = image_and_ROI.getFrame();

        if (video_frame.size().width>0 && video_frame.size().height>0) {
            imshow (this->window_name, video_frame);
        } else {
            imshow (this->window_name, frame); 
        }

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop
        if (cv::waitKey(10) == 27)
        {
            std::cout << "Esc key is pressed by user. Stopping the video" << std::endl;
            break;
        }

    }
}
