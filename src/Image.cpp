#include <opencv2/opencv.hpp>
#include "Image.h"

Image::Image() {
}

cv::Mat Image::getFrame() {
    return this->_frame;
}

void Image::setFrame(cv::Mat& frame) {
    this->_frame = frame;
}

cv::Mat Image::getROI() {
    return this->_roi_image;
}

void Image::setROI(cv::Mat& roi) {
    this->_roi_image = roi;
}

void Image::preprocess() {
    // convert to grayscale and resize to model input size


}