#include <opencv2/opencv.hpp>
#include "Model.h"


Model::Model(const std::string& model_filename) {
    // this reads in a pretrained (in python) tensorflow graph and weights
    // (.pb contains everything we need about the model)
    
    
}

void Model::Predict(cv::Mat& roi_image) {
    // this takes the region of interest image and then runs model inference


}


