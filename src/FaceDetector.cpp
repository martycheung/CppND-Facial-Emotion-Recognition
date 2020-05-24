#include <opencv2/opencv.hpp>
#include "FaceDetector.h"

using namespace cv;

FaceDetector::FaceDetector() {

     // Load the cascade classifier
    this->cascade.load( OPENCV_PATH + "data/haarcascades/haarcascade_frontalface_alt.xml" ) ;
    this->scale=1.5;
}

void FaceDetector::detectAndDraw( Mat& img, std::string window_name) {

    std::vector<Rect> faces;
    Mat gray_img;

    cvtColor( img, gray_img, COLOR_BGR2GRAY );
    equalizeHist( gray_img, gray_img );

    // Detect faces
    this->cascade.detectMultiScale( gray_img, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(100, 100) );

    for ( size_t i = 0; i < faces.size(); i++ ){
        Rect r = faces[i];

        // draw rectangle around face
        rectangle(img,
                     Point(r.x, r.y),
                     Point(r.x + r.width, r.y + r.height),
                     Scalar(255, 0, 0), 3, 8, 0);
    }

    imshow (window_name, img);

}