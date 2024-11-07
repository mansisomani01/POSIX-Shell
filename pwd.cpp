#include "headers.h"

void pwd()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr)
    {
        cout << cwd << endl;
    }
    else
    {
        cerr << "Error getting working directory" << std::endl;
    }
}