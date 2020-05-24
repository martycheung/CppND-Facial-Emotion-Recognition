#include <opencv2/opencv.hpp>
#include <iostream>
#include "Video.h"

Video::Video() {}

void Video::startShowVideo() {

    // initialise camera object
    cv::VideoCapture cap(0);
    frameWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    frameHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    std::cout << "Resolution of the video : " << frameWidth << " x " << frameHeight << std::endl;

    //create a window with the window name
    cv::namedWindow(window_name); 
    
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
        detector.detectAndDraw( frame, window_name);

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed within 10 ms, continue the loop 
        if (cv::waitKey(10) == 27)
        {
            std::cout << "Esc key is pressed by user. Stopping the video" << std::endl;
            break;
        }
    }


}