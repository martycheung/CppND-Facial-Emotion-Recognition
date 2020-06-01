#ifndef IMAGE_H
#define IMAGE_H

#include <opencv2/opencv.hpp>
#include <iostream>


/**
 * Image class contains the full frame of the image, the region of interest (ROI) of the image
 * and the image that is ready for input to the model
 */
class Image {

public: 
    //Constructor
    Image() {};
    //Destructor
    ~Image() {};

    cv::Mat getROI();
    void setROI(cv::Mat& roi_image);
    cv::Mat getFrame();
    void setFrame(cv::Mat& frame);
    void preprocessROI();

    cv::Mat getModelInput();

private:
    
    cv::Mat _frame;
    cv::Mat _roi_image;
    cv::Mat _model_input_image;

};

#endif