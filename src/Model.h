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
    // Constructor reads in a pretrained (in python) tensorflow graph and weights (.pb file contains everything we need about the model)
    // Also initialises the mapping from class id to the string label (ie. happy, angry, sad etc)  
    Model(const std::string& model_filename);

    //Destructor
    ~Model() {};

    // Model inference function takes image input and outputs the prediction label and the probability
    std::vector<std::string> predict(Image& image);

private:
    // Neural network model
    cv::dnn::Net network;

    // Mapping of the class id to the string label
    std::map<int, std::string> classid_to_string;

};


#endif