#include <fstream>
#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"
//test
int main(void){
	std::string imageName;
	std::cout << "start process" << std::endl;
	std::cout << "create file" << std::endl;
	std::ofstream ofs("output_file.csv");
	std::cout << "input file name" << std::endl;
	std::cin >> imageName;
//	cv::String str = "test.bmp";
	cv::Mat img = cv::imread(imageName);
	if(img.empty() == true) return 0;
	std::cout << "show file" << std::endl;
	std::cout << img.size().width << " " << img.size().height << std::endl;
	std::cout << img.channels() << std::endl;

	std::cout << "output file" << std::endl;
	for(int i = 0; i < img.size().height; ++i){
		for(int j = 0; j < img.size().width; ++j){
			ofs << std::to_string(img.at<cv::Vec3b>(i, j)[0]) << ",";
			std::cout << std::to_string(img.at<cv::Vec3b>(i, j)[0]) << ",";
		}
		ofs << std::endl;
		std::cout << std::endl;
	}
	cv::imshow(imageName,img);
	cv::waitKey();
	return 0;
}