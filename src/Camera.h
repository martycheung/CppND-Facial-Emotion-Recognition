#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include "FaceDetector.h"
#include "Model.h"
#Include "Image.h"

class Camera {

public: 

    Camera(const std::string& window_name);

    void captureVideo();
    void  displayVideo();

private:
    FaceDetector detector;
    
    double frameWidth;
    double frameHeight;
    Image image_and_ROI;
    cv::Mat frame;
    
    const std::string& window_name;
};

#endif
