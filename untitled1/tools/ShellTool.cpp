//
// Created by xinmei365 on 2019/1/1.
//

#include "ShellTool.h"

int32_t ShellTool::myexec(const char *cmd, vector<string> &resvec)
{
    resvec.clear();
    FILE *fp = popen(cmd, "r");
    if (!fp)
    {
        return -1;
    }
    char tmp[1024];
    while(fgets(tmp, sizeof(tmp), fp))
    {
        if (strlen(tmp) == 0)
        {
            break;
        }

        if (tmp[strlen(tmp) - 1] == '\n')
        {
            tmp[strlen(tmp) - 1] = '\0';
        }
        resvec.push_back(tmp);
    }

    return resvec.size();
}

int main()
{
    char *cmd = "ls -l";
    vector<string> vec;
    ShellTool::myexec(cmd, vec);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << i << ": " << vec[i] << endl;
    }
    return 0;
}
