#pragma once

#include "template/Parameter.h"

#include <opencv2/opencv.hpp>
#include <mutex>

#define IMG_MAX_CNT 100

class Image : public Parameter
{
    public:
        Image(){};
        Image(int id_){id = id_;};
        ~Image(){};
        int openFiles(std::string dir_name, std::string format);
        cv::Mat getImageMat(int idx);
        void pushImageMat(cv::Mat img);
        cv::Mat getCurImageMat();
        std::vector<std::string> getVecFiles() { return vec_files;};
    private:
        std::unordered_map<std::string, boost::variant<int , std::string>> params;
        int id = 0;
        std::string cur_file;
        // cv::Mat cur_img;
        int img_idx = 0;
        std::vector<cv::Mat> vec_mat;
        std::vector<std::string> vec_files;
        std::mutex mtx;
};
