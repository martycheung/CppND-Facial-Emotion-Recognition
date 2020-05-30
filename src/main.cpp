#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <algorithm>
#include <mutex>

#include "FaceDetector.h"
#include "Camera.h"
#include "Image.h"

// Update this with the path to your opencv directory
const std::string OPENCV_PATH = "/Users/martincheung/Documents/CMake/opencv-4.3.0/";

int main()
{

    // const std::string graph_def_filename = "model/saved_model.pb";
    // const std::string checkpoint_dir = "model/variables";
    // const std::string checkpoint_prefix = checkpoint_dir + "/variables"; 
    // bool restore = DirectoryExists(checkpoint_dir);

    // // Setup global state for TensorFlow.
    // tensorflow::port::InitMain(argv[0], &argc, &argv);

    // std::cout << "Loading graph\n";
    // Model model(graph_def_filename);

    // std::vector<std::vector<float>> testdata({create_sinus_wave(0.0, 50), create_sinus_wave(1.0, 50)});
    // std::cout << "Initial predictions\n";

    // model.Predict(testdata);

    // read data from txt
    // image = ReadBoardFile("/Users/martincheung/Desktop/Learning Resources/C++ Nanodegree/CppND-Facial-Emotion-Recognition/data/test.txt");
    // std::ifstream in("/Users/martincheung/Desktop/Learning Resources/C++ Nanodegree/CppND-Facial-Emotion-Recognition/data/test.txt");
    // std::vector<std::vector<double>> image;
    // if (in) {
    //     std::string line;
    //     while (std::getline(in, line)) {
    //         std::stringstream sep(line);
    //         std::string field;
    //         image.push_back(std::vector<double>());
    //         while (std::getline(sep, field, ',')) {
    //             image.back().push_back(std::stod(field));
    //         }
    //     }
    // }
    // for (auto row : image) {
    //     for (auto field : row) {
    //         std::cout << field << ' ';
    //     }
    //     std::cout << '\n';
    // }

    // // Thread 1: Perform Face Detect
    // std::thread t1(&FaceDetector::detectFaceAndDrawRoi);

    // // Model Inference
    // Model model;

    // // Thread 2: Process ROI Images and Model Inference
    // std::thread t2(&processImagesAndMakeInference, std::move(model));

    // Thread 2: Visualise Video Feed and Prediction  
    // Show camera + face detection - and if prediction exists, print text

    Camera cam("Martin's Laptop Camera");
    cam.displayVideo();    
    
    return 0;

}