#include <iostream>
#include "process_a.h"
using std::cout, std::endl;


// Process 

void Process::planProcess()
{
    cout << "this is planing process" << endl;
    my_map.mapInfo();
    cout << "planning sucess!" << endl;
}