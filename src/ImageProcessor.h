#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <opencv2/opencv.hpp>
#include <iostream>

class Video {

public: 

    Video();

    void startShowVideo();

private:
    FaceDetector detector;
    
    double frameWidth;
    double frameHeight;
    cv::Mat frame;

    const std::string window_name = "Martin's Laptop Camera";

};

#endif