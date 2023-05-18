#pragma once

#include "template/Parameter.h"

#include <opencv2/opencv.hpp>

class Image : public Parameter
{
    public:
        Image(){};
        Image(int idx){img_idx = idx;};
        ~Image(){};
        bool OpenImageFiles();
        int getImageFilesSize();
        cv::Mat getImageMat(int idx);
    private:
        std::unordered_map<std::string, boost::variant<int , std::string>> params;
        int img_idx = 0;
        std::vector<std::string> in_files;
};
