#include <opencv2/opencv.hpp>
using namespace cv;

extern const std::string OPENCV_PATH;

class FaceDetector {

public:

    FaceDetector();

    void detectAndDraw( Mat& img, std::string window_name);

private:
    CascadeClassifier cascade;
    double scale;

};
