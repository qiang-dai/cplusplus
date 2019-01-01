//
// Created by xinmei365 on 2018/12/31.
//
#include <boost/scoped_ptr.hpp>
#include "iostream"
#include "sstream"
#include "../tools/io_tool.h"
#include "../tools/sort.h"

using namespace std;
int main61()
{
    istringstream istr("1 56.7");
    cout << istr.str() << endl;

    string str = istr.str();
    cout << str << endl;

    int n;
    double d;
//    istr >> n;
//    istr >> d;
    cout << "d= " << d << endl;
    cout << "n= " << n << endl;

    istr >> d;
    istr >> n;

    cout << "d= " << d << endl;
    cout << "n= " << n << endl;

    return 0;
}

int main62()
{
    istringstream istr;
    string line, str;
    while(getline(cin, line)) {
        istr.str(line);
        while(istr >> str) {
            cout << str << endl;
        }
    }

    return 0;
}

int main63()
{
    write("a.txt", "good try");
    vector<string> vec;
    vec.push_back("a");
    vec.push_back("b");
    vec.push_back("c");
    vec.push_back("dd");

    write("b.txt", vec);

    vec.clear();
    string s = read_line("a.txt");
    cout << "s= " << s << endl;
    s = read_line("b.txt");
    cout << "s= " << s << endl;

    vec = read("b.txt", 2);
    for(int i = 0; i < vec.size(); i++) {
        cout << i << ": " << vec[i] << endl;
    }
    list<string> tmp_list = read_list("b.txt");
    list<string>::iterator it;
    for(it = tmp_list.begin(); it != tmp_list.end(); ++it) {
        cout << "list item: " << *it << endl;
    }

    long size = get_files_size("/Users/xinmei365/Parallels/Windows 10.pvm/Windows 10-0.hdd/Windows 10-0.hdd.0.{5fbaabe3-6958-40ff-92a7-860e329aab41}.hds");
    cout << "size= " << size << endl;
    cout << size_to_read(size) << endl;
    cout << "long2string:" << long2string(size) << endl;
    size = get_files_size("a.txt");
    cout << "size= " << size << endl;
    cout << size_to_read(size) << endl;
    cout << "long2string:" << long2string(size) << endl;


    stringstream ostr("ccc");
    ostr.put('d');
    ostr.put('e');
    ostr<<"fg";
    string gstr = ostr.str();
    cout<<gstr<<endl;

    char a;
    ostr>>a;
    cout<<a << endl;

    cout << string2int("12354") << endl;
    cout << string2long("1234567891234") << endl;
    cout << string2double("1.3542") << endl;

    string i = int2string(1234);
    string l = long2string(7848484848484848);
    string d = double2string(3.2257);
    cout << i << endl;
    cout << l << endl;
    cout << d << endl;
}

int main66()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(5);
    vec.push_back(7);
    sort_vector(vec);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << i << ": " << vec[i] << endl;
    }

    boost::scoped_ptr<char> scoped_ptr(read_binary("b.txt"));
    cout << scoped_ptr.operator*() << endl;
    cout << scoped_ptr.operator->() << endl;
}