//
// Created by xinmei365 on 2019/1/1.
//

#include "IOTool.h"
///////////////////////////////////////////////////
string IOTool::read_line(const string filename) {
    char buffer[256];
    ifstream in(filename);
    if (!in.is_open())
    {
        cout << "Error opening file:" + filename << endl;
        exit(1);
    }

    while(!in.eof())
    {
        in.getline(buffer, 255);
        break;
    }
    in.close();
    return buffer;
}
list<string> IOTool::read(const string filename, int limit) {
    char buffer[256];
    ifstream in(filename);
    if (!in.is_open())
    {
        cout << "Error opening file:" + filename << endl;
    }

    list<string> vec;
    while (!in.eof())
    {
        in.getline(buffer, 255);
        vec.push_back(buffer);
        if (vec.size() >= limit) {
            break;
        }
    }
    in.close();
    //trim last empty string
    if (vec.size() > 0 && strncmp(buffer, ".", 1) == 0) {
        vec.pop_back();
    }

    return vec;
}
list<string> IOTool::read_list(const string filename, int limit) {
    char buffer[256];
    ifstream in(filename);
    if (!in.is_open())
    {
        cout << "Error opening file:" + filename << endl;
    }

    list<string> tmp_list;
    while (!in.eof())
    {
        in.getline(buffer, 255);
        tmp_list.push_back(buffer);
        if (tmp_list.size() >= limit) {
            break;
        }
    }
    in.close();
    //trim last empty string
    if (tmp_list.size() > 0 && buffer[0] == '\0') {
        tmp_list.pop_back();
    }


    return tmp_list;
}
///////////////////////////////////////////////////
char *IOTool::read_binary(const string filename)
{
    long size = get_files_size(filename);
    char *buffer = new char[size];
    ifstream in(filename, ios::in|ios::binary);
    in.read(buffer, size);
    in.close();

//    for(int i = 0; i < size; i++)
//    {
//        cout << (char)(*(buffer + i)) << endl;
//    }

    return buffer;
}
///////////////////////////////////////////////////
bool IOTool::write(const string filename, string line) {
    ofstream out(filename);
    if (out.is_open())
    {
        out << line << endl;
    }
    return true;
}

bool IOTool::write(const string filename, list<string> &line_list)
{
    ofstream out(filename);
    list<string>::iterator it;
    for(it = line_list.begin(); it != line_list.end(); ++it)
    {
        out << *it << endl;
    }
    return true;
}
///////////////////////////////////////////////////
long IOTool::get_files_size(const string filename)
{
    long l,m;
    ifstream in(filename, ios::in|ios::binary);
    l = in.tellg();
    in.seekg(0, ios::end);
    m = in.tellg();
    in.close();

    return m - l;
}

string IOTool::long2string(long v)
{
    ostringstream ss;
    ss << v;
    return ss.str();
}
string IOTool::int2string(int v)
{
    ostringstream ss;
    ss << v;
    return ss.str();
}
string IOTool::double2string(double v)
{
    ostringstream ss;
    ss << v;
    return ss.str();
}
int IOTool::string2int(const string &s)
{
    int n;
    stringstream ss;
    ss << s;
    ss >> n;
    return n;
}
long IOTool::string2long(const string &s)
{
    long n;
    stringstream ss;
    ss << s;
    ss >> n;
    return n;
}
double IOTool::string2double(const string &s)
{
    double n;
    stringstream ss;
    ss << s;
    ss >> n;
    return n;
}
string IOTool::size_to_read(long size)
{
    static char arr[3] = {'K', 'M', 'G'};
    int unit = 1024;
    string s = "";
    for(int i = -1; i < 3; i++)
    {
        int v = size%unit;
        string tmp = int2string(v);

        if (v != 0)
        {
            if ( i >= 0)
            {
                s = ' ' + s;
                s = arr[i] + s;
            }
            s = tmp + s;
        }

        size = size/unit;
        if (size == 0) {
            break;
        }
    }
    return s;
}

string IOTool::replace(string &src, char c, char d)
{
    string::iterator it = find(src.begin(), src.end(), c);
    while(it != src.end())
    {
        auto x = src.erase(it);
        src.insert(x, d);
        it = find(x, src.end(), c);
    }
    return src;
}

string IOTool::replace_first(string &src, char c, char d)
{
    string::iterator it = find(src.begin(), src.end(), c);
    while(it != src.end())
    {
        auto x = src.erase(it);
        src.insert(x, d);
        it = find(x, src.end(), c);

        break;
    }
    return src;
}




int mainiot3()
{
    IOTool::write("a.txt", "good try");
    vector<string> vec;
    vec.push_back("a");
    vec.push_back("b");
    vec.push_back("c");
    vec.push_back("dd");

    list<string> list_tmp;
    IOTool::write("b.txt", list_tmp);

    vec.clear();
    string s = IOTool::read_line("a.txt");
    cout << "s= " << s << endl;
    s = IOTool::read_line("b.txt");
    cout << "s= " << s << endl;

    list_tmp = IOTool::read("b.txt", 2);
    for(int i = 0; i < vec.size(); i++) {
        cout << i << ": " << vec[i] << endl;
    }
    list_tmp = IOTool::read_list("b.txt");
    list<string>::iterator it;
    for(it = list_tmp.begin(); it != list_tmp.end(); ++it) {
        cout << "list item: " << *it << endl;
    }

    long size = IOTool::get_files_size("/Users/xinmei365/Parallels/Windows 10.pvm/Windows 10-0.hdd/Windows 10-0.hdd.0.{5fbaabe3-6958-40ff-92a7-860e329aab41}.hds");
    cout << "size= " << size << endl;
    cout << IOTool::size_to_read(size) << endl;
    cout << "long2string:" << IOTool::long2string(size) << endl;
    size = IOTool::get_files_size("a.txt");
    cout << "size= " << size << endl;
    cout << IOTool::size_to_read(size) << endl;
    cout << "long2string:" << IOTool::long2string(size) << endl;


    stringstream ostr("ccc");
    ostr.put('d');
    ostr.put('e');
    ostr<<"fg";
    string gstr = ostr.str();
    cout<<gstr<<endl;

    char a;
    ostr>>a;
    cout<<a << endl;

    cout << IOTool::string2int("12354") << endl;
    cout << IOTool::string2long("1234567891234") << endl;
    cout << IOTool::string2double("1.3542") << endl;

    string i = IOTool::int2string(1234);
    string l = IOTool::long2string(7848484848484848);
    string d = IOTool::double2string(3.2257);
    cout << i << endl;
    cout << l << endl;
    cout << d << endl;


    vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(3);
    vec2.push_back(9);
    vec2.push_back(5);
    vec2.push_back(7);
    for(int i = 0; i < vec2.size(); i++)
    {
        cout << i << ": " << vec2[i] << endl;
    }

    boost::scoped_ptr<char> scoped_ptr(IOTool::read_binary("b.txt"));
    cout << scoped_ptr.operator*() << endl;
    cout << scoped_ptr.operator->() << endl;

    return 0;
}