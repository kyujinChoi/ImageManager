#pragma once

#include "template/Parameter.h"

#include <opencv2/opencv.hpp>
#include <mutex>

#define IMG_MAX_CNT 10

class Image : public Parameter
{
    public:
        Image(){vec_mat.resize(100);};
        Image(int id_){id = id_;vec_mat.resize(100);};
        ~Image(){};
        int openFiles(std::string dir_name, std::string format);
        cv::Mat getImageMat(int idx);
        void pushImageMat(cv::Mat img);
        cv::Mat getCurImageMat();
        std::vector<std::string> getVecFiles() { return vec_files;};
    private:
        std::unordered_map<std::string, boost::variant<int , std::string>> params;
        int id = 0;
        
        // cv::Mat cur_img;
        int img_idx = -1;
        std::vector<cv::Mat> vec_mat;
        std::vector<std::string> vec_files;
        std::mutex mtx;
};
