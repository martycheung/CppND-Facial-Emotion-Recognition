#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <opencv2/opencv.hpp>

#include "Image.h"

extern const std::string OPENCV_PATH;

class FaceDetector {

public:

    FaceDetector();
    Image detectFaceAndDrawRoi( cv::Mat& img);

private:
    cv::CascadeClassifier cascade;
    double scale;

    std::vector<cv::Rect> faces;
    
};

#endif