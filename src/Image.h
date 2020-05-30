#ifndef IMAGE_H
#define IMAGE_H

#include <opencv2/opencv.hpp>
#include <iostream>


extern const std::string OPENCV_PATH;

/**
 * Image class contains both the full frame of the image and the region of interest (ROI) of the image
 * 
 */
class Image {

public: 

    Image();

    cv::Mat getROI();
    void setROI(cv::Mat& roi_image);
    cv::Mat getFrame();
    void setFrame(cv::Mat& frame);
    void preprocess();

private:
    
    cv::Mat _frame;
    cv::Mat _roi_image;

};

#endif