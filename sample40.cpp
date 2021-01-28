#include "list.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    list<int> lst;
    
    lst.add(2);
    lst.add(3);
    lst.add(3);
    lst.add(4);

    for (int i = 0; i < lst.size(); ++i)
    {
        cout << lst[i] << endl;
    }

    lst.remove(3);

    for (int i = 0; i < lst.size(); ++i)
    {
        cout << lst[i] << endl;
    }
    
    return 0;
}