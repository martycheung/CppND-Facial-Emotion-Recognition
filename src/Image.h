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

    // Getter for the ROI image
    cv::Mat getROI();
    // Setter for the ROI image
    void setROI(cv::Mat& roi_image);
    // Getter for the video frame
    cv::Mat getFrame();
    // Setter for the video frame
    void setFrame(cv::Mat& frame);
    // Function to preprocess image for model input
    void preprocessROI();
    // Save the original raw video frame without the bounding box or text
    void setOriginalFrame(cv::Mat& original_frame);
    // Getter for the model input image
    cv::Mat getModelInput();

private:
    
    cv::Mat _original_frame;
    cv::Mat _frame;
    cv::Mat _roi_image;
    cv::Mat _model_input_image;

};

#endif