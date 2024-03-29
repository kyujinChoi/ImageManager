#pragma once

#include "Image.h"

class ImageManager 
{
    
    public:
        ImageManager();
        ~ImageManager(){};
        std::shared_ptr<Image> getImageModule(int idx);
        int initImageModule();
        int openFiles(int id, std::string dir_name);
    private:
        std::vector<std::shared_ptr<Image>> vec_Images;
};
