#include <opencv2/opencv.hpp>

#include "Model.h"

Model::Model(const std::string& model_filename) 
    : network(cv::dnn::readNet(model_filename)), // Load the tensorflow model 
      classid_to_string({{0, "Angry"}, 
                         {1, "Disgust"}, 
                         {2, "Fear"}, 
                         {3, "Happy"}, 
                         {4, "Sad"}, 
                         {5, "Surprise"}, 
                         {6, "Neutral"}}) // Create a map from class id to the class labels
{}

std::string Model::predict(Image& image) {
    // this takes the region of interest image and then runs model inference
    cv::Mat roi_image = image.getModelInput();

    // Convert to blob
    cv::Mat blob = cv::dnn::blobFromImage(roi_image);

    // Pass blob to network
    this->network.setInput(blob);

    // Forward pass on network    
    cv::Mat prob = this->network.forward();

    // Sort the probabilities and rank the indicies
    cv::Mat sorted_probabilities;
    cv::Mat sorted_ids;
    cv::sort(prob.reshape(1, 1), sorted_probabilities, cv::SORT_DESCENDING);
    cv::sortIdx(prob.reshape(1, 1), sorted_ids, cv::SORT_DESCENDING);

    // Get top probability and top class id
    float top_probability = sorted_probabilities.at<float>(0);
    int top_class_id = sorted_ids.at<int>(0);

    // Map classId to the class name string (ie. happy, sad, angry, disgust etc.)
    std::string class_name = this->classid_to_string.at(top_class_id);

    // Prediction result string to print
    std::string result_string = class_name + ": " + std::to_string(top_probability * 100) + "%";

    return result_string;

}


