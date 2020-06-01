#include <opencv2/opencv.hpp>
#include "FaceDetector.h"
#include "Image.h"

FaceDetector::FaceDetector() {

     // Load the cascade classifier
    cascade.load( OPENCV_PATH + "data/haarcascades/haarcascade_frontalface_alt.xml" ) ;
    scale=1.5;

}

Image FaceDetector::detectFaceAndDrawRoi( cv::Mat& frame) {
    Image image_and_ROI;
    cv::Mat gray_img;
    cv::cvtColor( frame, gray_img, cv::COLOR_BGR2GRAY );
    cv::equalizeHist( gray_img, gray_img );

    // Detect faces
    cascade.detectMultiScale( gray_img, faces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(100, 100) );

    // Just the one face to simplify things. We will simply pick the first face, if there is at least 1 face detected
    if (faces.size() > 0) { 
        
        cv::Rect r = faces[0];

        // draw rectangle around face
        rectangle(frame,
                    cv::Point(r.x, r.y),
                    cv::Point(r.x + r.width, r.y + r.height),
                    cv::Scalar(255, 0, 0), 3, 8, 0);

        cv::Rect roi_coord(r.x, r.y,r.width,r.height);

        cv::Mat roi_image = frame(roi_coord);

        image_and_ROI.setROI(roi_image);
        image_and_ROI.setFrame(frame);

    }   

    

    return image_and_ROI;

}

Image FaceDetector::addPredictionTexttoFrame( Image image_and_ROI, std::string& emotion_prediction) {

    cv::Mat img = image_and_ROI.getFrame();

    if (faces.size() > 0) { 
        cv::Rect r = faces[0];

        // Write text prediction on bounding box
        cv::putText(img, //target image
                    emotion_prediction, //text - will take the output of the model.inference()
                    cv::Point(r.x, r.y-10), //top-left position
                    cv::FONT_HERSHEY_DUPLEX,
                    1.0,
                    CV_RGB(118, 185, 0), //font color
                    2);
    }

    image_and_ROI.setFrame(img);

    return image_and_ROI;

}