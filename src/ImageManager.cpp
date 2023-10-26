#include "ImageManager.h"

ImageManager::ImageManager()
{
    // for(int i = 0 ; i < 5; i++)
    // {
    //     std::string fn = "/home/ckj/my_github/trigger_generator_ubuntu/0_sample/img/" + std::to_string(i);
    //     openDir(fn);
    // }
}
int ImageManager::initImageModule()
{
    std::shared_ptr<Image> objImage = std::make_shared<Image>(vec_Images.size());
    vec_Images.push_back(objImage);
    return vec_Images.size() - 1;
}
// int ImageManager::openFiles(int id, std::string dir_name)
// {
//     if(id >= vec_Images.size())
//         return -1;
//     vec_Images[id]->insertParam("input_dir", dir_name);
//     if(vec_Images[id]->OpenImageFiles())
//         return id;
//     return -1;
// }
std::shared_ptr<Image> ImageManager::getImageModule(int idx)
{
    if(idx >= 0 && idx < vec_Images.size())
        return vec_Images[idx];
    return NULL;
}

