#include <opencv2/opencv.hpp>
#include "FaceDetector.h"

FaceDetector::FaceDetector() {

     // Load the cascade classifier
    this->cascade.load( OPENCV_PATH + "data/haarcascades/haarcascade_frontalface_alt.xml" ) ;
    this->scale=1.5;
}

void FaceDetector::detectAndDraw( cv::Mat& img, std::string window_name) {

    cv::cvtColor( img, gray_img, cv::COLOR_BGR2GRAY );
    cv::equalizeHist( gray_img, gray_img );

    // Detect faces
    this->cascade.detectMultiScale( gray_img, faces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(100, 100) );

    for (size_t i = 0; i < faces.size(); i++) {
        cv::Rect r = faces[i];

        // draw rectangle around face
        rectangle(img,
                     cv::Point(r.x, r.y),
                     cv::Point(r.x + r.width, r.y + r.height),
                     cv::Scalar(255, 0, 0), 3, 8, 0);

        cv::Rect roi(r.x, r.y,r.width,r.height);
        roi_images.push_back(img(roi));

    }


    // Mat resized;

    // if (roi_image.size().width>0 && roi_image.size().height>0) {
    //     resize(roi_image, resized, Size(720, 720), 0, 0, INTER_LINEAR);
    //     imshow (window_name, resized);
    // }

    if (img.size().width>0 && img.size().height>0) {
        imshow (window_name, img);
    }

}