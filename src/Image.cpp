
#include "Image.h"
#include <dirent.h>
#include <algorithm>
#include <cstring>

cv::Mat Image::getCurImageMat()
{
    mtx.lock();
    int result = img_idx;
    mtx.unlock();
    
    return vec_mat[result];
}
void Image::pushImageMat(cv::Mat img)
{
    mtx.lock();
    vec_mat[++img_idx % IMG_MAX_CNT] = img;
    mtx.unlock();
    return;
}
int Image::openFiles(std::string dir_name, std::string format)
{   
    insertParam("input_dir", dir_name);
    struct dirent *entry;

    DIR *dir = opendir(dir_name.c_str());

    if (dir == NULL)
    {
        std::cout << "OpenImageFiles : cannot find " << getParamStr("input_dir") << std::endl;
        exit(0);
    }
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        std::string img_fn(entry->d_name);
        std::string full_path = getParamStr("input_dir") + "/" + entry->d_name;
        vec_files.push_back(full_path);
        // std::cout << "Image::OpenImageFiles : " << full_path << std::endl;
    }
    sort(vec_files.begin(), vec_files.end());
    closedir(dir);

    return vec_files.size();
}

cv::Mat Image::getImageMat(int idx)
{
    cv::Mat empty;
    
    if(!vec_mat[idx].empty() && img_idx == idx)
        return vec_mat[idx];
    if (idx < vec_mat.size())
    {
        pushImageMat(cv::imread(vec_files[idx]));
        return getCurImageMat();
    }
    else
        return empty;
}


