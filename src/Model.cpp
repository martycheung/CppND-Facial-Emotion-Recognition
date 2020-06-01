#include <opencv2/opencv.hpp>

#include "Model.h"

Model::Model(const std::string& model_filename) {
    network = cv::dnn::readNet(model_filename);
    classid_to_string = {{0, "Angry"}, 
                                     {1, "Disgust"}, 
                                     {2, "Fear"}, 
                                     {3, "Happy"}, 
                                     {4, "Sad"}, 
                                     {5, "Surprise"}, 
                                     {6, "Neutral"}};
}

std::string Model::predict(Image& image) {
    // this takes the region of interest image and then runs model inference
    cv::Mat roi_image = image.getModelInput();

    // Convert to blob
    cv::Mat blob = cv::dnn::blobFromImage(roi_image);

    // Pass blob to network
    this->network.setInput(blob);

    // Forward pass on network    
    cv::Mat prob = this->network.forward();

    // Get class id with highest probability
    cv::Point classIdPoint;
    double confidence;
    cv::minMaxLoc(prob.reshape(1, 1), 0, &confidence, 0, &classIdPoint);
    int classId = classIdPoint.x;

    // Map classId to the class name string (ie. happy, sad, angry, disgust etc.)
    std::string class_name = this->classid_to_string.at(classId);

    // std::cout << prob.reshape(1, 1) << std::endl;

    return class_name + " " + std::to_string(confidence);

}


