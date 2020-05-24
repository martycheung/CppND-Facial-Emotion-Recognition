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

    std::vector<cv::Mat> roi_images;
    std::vector<cv::Rect> faces;
    cv::Mat gray_img;

};

#endif