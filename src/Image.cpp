
#include "Image.h"
#include <dirent.h>
#include <algorithm>
#include <cstring>

bool Image::OpenImageFiles()
{
    struct dirent *entry;

    DIR *dir = opendir(getParamStr("input_dir").c_str());

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
        in_files.push_back(full_path);
        // std::cout << "Image::OpenImageFiles : " << full_path << std::endl;
    }
    sort(in_files.begin(), in_files.end());
    closedir(dir);

    return true;
}

cv::Mat Image::getImageMat(int idx)
{
    cv::Mat empty;
    if(cur_file == in_files[idx])
        return cur_img;
    if (idx < in_files.size())
    {
        cur_file = in_files[idx];
        cur_img = cv::imread(in_files[idx]);
        return cur_img;
    }
    else
        return empty;
}
int Image::getImageFilesSize()
{
    return in_files.size();
}

