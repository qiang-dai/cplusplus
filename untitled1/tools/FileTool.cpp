//
// Created by xinmei365 on 2019/1/1.
//

#include "FileTool.h"
#include <dirent.h>
#include <iostream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include "boost/scoped_ptr.hpp"
#include <limits.h>
#include <stdlib.h>
#include <cstring>

string FileTool::get_pure_dir(const string &s)
{
    size_t pos = s.rfind('/');
    if (pos != string::npos)
    {
        return s.substr(0, pos+1);
    }
    return s;
}
string FileTool::get_absolute_dir(const string &input_path)
{
    char path[256] = {0};
    if (input_path.size() > PATH_MAX || NULL==realpath(input_path.c_str(),path))
    {
        return path;
    }
    return path;
}
bool FileTool::is_exist(const string &filename)
{
    if (access(filename.c_str(), F_OK) == 0)
    {
        return true;
    }
    return false;
}

bool FileTool::is_readable(const string &filename)
{
    if (!is_exist(filename))
    {
        return false;
    }
    if (access(filename.c_str(), R_OK) != 0)
    {
        return false;
    }
    return true;
}
bool FileTool::is_writable(const string &filename)
{
    if (!is_exist(filename))
    {
        return false;
    }
    if (access(filename.c_str(), W_OK) != 0)
    {
        return false;
    }
    return true;
}
bool FileTool::is_executable(const string &filename)
{
    if (!is_exist(filename))
    {
        return false;
    }
    if (access(filename.c_str(), X_OK) != 0)
    {
        return false;
    }
    return true;
}
//get short name
string FileTool::get_short_name(const string &s)
{
    size_t pos = s.rfind('/');
    if (pos != string::npos)
    {
        return s.substr(pos+1);
    }
    return s;
}

string FileTool::get_suffix(const string &s)
{
    size_t pos = s.rfind('.');
    if (pos != string::npos)
    {
        return s.substr(pos+1);
    }
    return s;
}
//tail with '/'
string FileTool::format_dir(string &s)
{
    if (s.size() == 0)
    {
        return s;
    }
    if (s[s.size() - 1] != '/')
    {
        s += '/';
    }
    return s;
}

list<string> FileTool::get_files(const string dir, bool is_recursive)
{
    list<string> file_name;
    list<string> dir_name;
    get_files(dir, file_name, dir_name, is_recursive);
    return file_name;
}
int FileTool::get_files(const string path, list<string> &file_name, list<string> &dir_name, bool is_recursive)
{
    struct dirent *dirp;

    //DIR* dir = opendir(path.c_str());
    boost::scoped_ptr<DIR> scp_dir(opendir(path.c_str()));

    while ((dirp = readdir(scp_dir.get())) != nullptr) {
        if (dirp->d_type == DT_REG) {
            // 文件
            //printf("%s\n", dirp->d_name);
            file_name.push_back(path + "/" + dirp->d_name);

        } else if (dirp->d_type == DT_DIR) {
            // 文件夹
            if (strncmp(dirp->d_name, ".", 2) == 0)
            {
                //pass
            }
            else if (strncmp(dirp->d_name, "..", 3) == 0)
            {
                //pass
            }
            else
            {
                dir_name.push_back(path + "/" + dirp->d_name);
                if (is_recursive)
                {
                    get_files(path + "/" + dirp->d_name, file_name, dir_name, is_recursive);
                }

            }
        }
    }
    return 0;
}

//list<string> FileTool::get_files(string path, list<string> &file_name, list<string> &dir_name)
//{
//    file_name.clear();
//    dir_name.clear();
//
//    DIR* dirp = opendir(path.c_str());
//    if(!dirp)
//    {
//        return file_name;
//    }
//    struct stat st;
//    struct dirent *dir;
//    while((dir = readdir(dirp)) != NULL)
//    {
//        if(strcmp(dir->d_name,".") == 0 ||
//           strcmp(dir->d_name,"..") == 0)
//        {
//            continue;
//        }
//        string full_path = path + dir->d_name;
//
//        /////////////////////////////////////////failed when running this line
//        if(lstat(full_path.c_str(),&st) == -1)
//        {
//            continue;
//        }
//        string name = dir->d_name;
//
//        //replace the blank char in name with "%$".
//        while(name.find(" ") != string::npos)
//        {
//            name.replace(name.find(" "),1,"$%");
//        }
//
//        if(S_ISDIR(st.st_mode))   //S_ISDIR()宏判断是否是目录文件
//        {
//            //name += "[d]";
//            dir_name.push_back(name);
//        }
//        else
//        {
//            file_name.push_back(name);
//        }
//    }
//
//    closedir(dirp);
//
//    return file_name;
//}
list<string> FileTool::get_dirs(const string dir, bool is_recursive)
{
    list<string> file_name;
    list<string> dir_name;
    get_files(dir, file_name, dir_name, is_recursive);
    return dir_name;
}


int mainft1()
{
    //list<string> ls = FileTool::get_files("/Users/xinmei365/kika-content-manager", true);
    list<string> ls = FileTool::get_files(".", true);
    list<string>::iterator it;
    for(it = ls.begin(); it != ls.end(); ++it)
    {
        cout << *it << endl;
        cout << FileTool::get_pure_dir(*it) << endl;
        cout << FileTool::get_short_name(*it) << endl;
        cout << FileTool::get_suffix(*it) << endl;
        cout << FileTool::get_absolute_dir(*it) << endl;
        cout << FileTool::is_exist(*it) << " " << FileTool::is_readable(*it) << endl;
        cout << FileTool::is_writable(*it) << " " << FileTool::is_executable(*it) << endl;
    }

    cout << "//////////////////////////" << endl;

    //list<string> ds = FileTool::get_dirs("/Users/xinmei365/kika-content-manager", true);
    list<string> ds = FileTool::get_dirs(".", true);
    for(it = ds.begin(); it != ds.end(); ++it)
    {
        cout << *it << endl;
        cout << FileTool::format_dir(*it) << endl;
    }

    return 0;
}