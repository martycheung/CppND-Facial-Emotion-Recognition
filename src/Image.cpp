#include <opencv2/opencv.hpp>

#include "Image.h"

cv::Mat Image::getFrame() {
    return this->_frame;
}

void Image::setFrame(cv::Mat& frame) {
    this->_frame = frame;
}

cv::Mat Image::getROI() {
    return this->_roi_image;
}

cv::Mat Image::getModelInput() {
    return this->_model_input_image;
}

void Image::setROI(cv::Mat& roi) {
    this->_roi_image = roi;
}

void Image::preprocessROI() {
    // convert to grayscale 
    cv::Mat gray_image;
    cv::cvtColor( this->_roi_image, gray_image, cv::COLOR_BGR2GRAY );

    // Resize the ROI to model input size
    cv::resize(gray_image, this->_model_input_image, cv::Size(48,48));

    // Convert image pixels from between 0-255 to 0-1
    this->_model_input_image.convertTo(this->_model_input_image, CV_32FC3, 1.f/255);

}

void Image::setOriginalFrame(cv::Mat& original_frame) {
    this->_original_frame = original_frame;
}