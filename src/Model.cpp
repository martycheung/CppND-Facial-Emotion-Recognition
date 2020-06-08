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

std::vector<std::string> Model::predict(Image& image) {
    // this takes the region of interest image and then runs model inference
    std::vector<cv::Mat> roi_image = image.getModelInput();

    std::vector<std::string> emotion_prediction;

    if (roi_image.size() > 0) { 
        for (int i=0; i < roi_image.size(); i++) {
            // Convert to blob
            cv::Mat blob = cv::dnn::blobFromImage(roi_image[i]);

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

            // Put on end of result vector
            emotion_prediction.push_back(result_string);

        }
    }

    return emotion_prediction;

}


