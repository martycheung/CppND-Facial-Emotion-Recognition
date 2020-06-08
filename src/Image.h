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
    std::vector<cv::Mat> getROI();
    // Setter for the ROI image
    void setROI(cv::Mat& roi);
    // Getter for the video frame
    cv::Mat getFrame();
    // Setter for the video frame
    void setFrame(cv::Mat& frame);
    // Function to preprocess image for model input
    void preprocessROI();
    // Getter for the model input image
    std::vector<cv::Mat> getModelInput();

private:
    // the full video frame
    cv::Mat _frame;
    // region of interest within the bounding box
    std::vector<cv::Mat> _roi_image;
    // preprocessed image ready for model
    std::vector<cv::Mat>  _model_input_image;

};

#endif