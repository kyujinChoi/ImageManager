#include "ImageManager.h"

ImageManager::ImageManager()
{
    // for(int i = 0 ; i < 5; i++)
    // {
    //     std::string fn = "/home/ckj/my_github/trigger_generator_ubuntu/0_sample/img/" + std::to_string(i);
    //     openDir(fn);
    // }
}
std::shared_ptr<Image> ImageManager::getImageModule(int idx)
{
    if(idx >= vec_Images.size())
        return NULL;
    return vec_Images[idx];
}
int ImageManager::openFiles(std::string dir_name)
{
    std::shared_ptr<Image> objImage = std::make_shared<Image>(vec_Images.size());
    objImage->insertParam("input_dir", dir_name);
    if(objImage->OpenImageFiles())
    {
        vec_Images.push_back(objImage);
        return vec_Images.size() - 1;
    }
    return -1;
}
