#include <opencv2/opencv.hpp>
#include <iostream>
#include "FaceDetector.h"

using namespace cv;
using namespace std;

void startShowVideo() {

    //Open the default video camera
    VideoCapture cap(0);

    // if not success, exit program
    if (cap.isOpened() == false)  
    {
        std::cout << "Cannot open the video camera" << std::endl;
        std::cin.get(); //wait for any key press
    } 

    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    std::cout << "Resolution of the video : " << dWidth << " x " << dHeight << std::endl;

    std::string window_name = "My Camera Feed";
    namedWindow(window_name); //create a window called "My Camera Feed"

    FaceDetector detector;
    
    while (true)
    {
        Mat frame;
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
        if (waitKey(10) == 27)
        {
            std::cout << "Esc key is pressed by user. Stopping the video" << std::endl;
            break;
        }
    }


}