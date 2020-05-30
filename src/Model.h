#ifndef MODEL_H
#define MODEL_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include "Image.h"

/**
 * Model class that contains code to read the pretrained tensorflow model and allows
 * us to make predictions on new images
 */
class Model {
public:
    Model(const std::string& model_filename);

    std::string predict(Image& image);

private:

    cv::dnn::Net network;
    std::map<int, std::string> classid_to_string;

};


#endif