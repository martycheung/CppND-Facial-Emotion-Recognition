#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <opencv2/opencv.hpp>

extern const std::string OPENCV_PATH;

class FaceDetector {

public:

    FaceDetector();

    void detectAndDraw( cv::Mat& img, std::string window_name);

private:
    cv::CascadeClassifier cascade;
    double scale;

    cv::Mat roi_image;

};

#endif