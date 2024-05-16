#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::string imagePath = "ultimate_pitch_1872x680_USAU.png";
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
    cv::imshow("Display window", image);
    cv::waitKey(0);
    return 0;
}