#include <opencv2/opencv.hpp>

#include "Image.h"

cv::Mat Image::getFrame() {
    return this->_frame;
}

void Image::setFrame(cv::Mat& frame) {
    this->_frame = frame;
}

std::vector<cv::Mat> Image::getROI() {
    return this->_roi_image;
}

std::vector<cv::Mat> Image::getModelInput() {
    return this->_model_input_image;
}

void Image::setROI(cv::Mat& roi) {
    this->_roi_image.push_back(roi);
}

void Image::preprocessROI() {

    cv::Mat processed_image;

    if (_roi_image.size() > 0) { 
        for (int i=0; i < _roi_image.size(); i++) {

                // convert to grayscale 
                cv::Mat gray_image;
                cv::cvtColor( _roi_image[i], gray_image, cv::COLOR_BGR2GRAY );

                // Resize the ROI to model input size
                cv::resize(gray_image, processed_image, cv::Size(48,48));

                // Convert image pixels from between 0-255 to 0-1
                processed_image.convertTo(processed_image, CV_32FC3, 1.f/255);

                // Append onto the model input vector
                _model_input_image.push_back(processed_image);
        }
    }

}