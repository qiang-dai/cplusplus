//
// Created by xinmei365 on 2019/1/1.
//

#ifndef UNTITLED1_FILETOOL_H
#define UNTITLED1_FILETOOL_H

#include "iostream"
#include "list"
#include "vector"

using namespace std;
class FileTool
{
public:
    //without short name
    static string get_pure_dir(const string &s);
    static string get_absolute_dir(const string &s);
    //get short name
    static string get_short_name(const string &s);
    //without dot, like mp4
    static string get_suffix(const string &s);
    //tail with '/'
    static string format_dir(string &s);
    static list<string> get_files(const string dir, bool is_recursive = false);
    static list<string> get_dirs(const string dir, bool is_recursive = false);
    static int get_files(const string path, list<string> &file_name, list<string> &dir_name,
            bool is_recursive = false);
};

int main()
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
#endif //UNTITLED1_FILETOOL_H
