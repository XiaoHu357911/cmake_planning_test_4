#include <iostream>
#include "process.h"
using std::cout, std::endl;


// Process 

void Process::planProcess()
{
    cout << "this is planing process" << endl;
    my_map.mapInfo();
    cout << "planning sucess!" << endl;
}