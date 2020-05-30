#ifndef MODEL_H
#define MODEL_H

#include <opencv2/opencv.hpp>
#include <iostream>

/**
 * Model class that contains code to read the pretrained tensorflow model and allows
 * us to make predictions on new images
 */
class Model {
public:
    Model(const std::string& model_filename);

    void Predict(cv::Mat& roi_image);

private:

};


#endif