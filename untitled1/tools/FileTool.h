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
    static string get_pure_dir(string s);
    //get short name
    static string get_short_name(string s);
    //tail with '/'
    static string format_dir(string s);
    static list<string> get_files(string dir, bool is_recursive = false);
    static list<string> get_dirs(string dir, bool is_recursive = false);
    static int get_files(string path, list<string> &file_name, list<string> &dir_name,
            bool is_recursive = false);
};

int main()
{
    list<string> ls = FileTool::get_files("/Users/xinmei365/kika-content-manager", true);
    list<string>::iterator it;
    for(it = ls.begin(); it != ls.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << "//////////////////////////" << endl;

    list<string> ds = FileTool::get_dirs("/Users/xinmei365/kika-content-manager", true);
    for(it = ds.begin(); it != ds.end(); ++it)
    {
        cout << *it << endl;
    }
}
#endif //UNTITLED1_FILETOOL_H
