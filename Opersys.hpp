//
//  Opersys.hpp
//  OS-Tester
//
//  Created by Nosayba Hamada on 10/5/19.
//  Copyright © 2019 Nosayba Hamada. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>
using namespace std;



#ifndef Opersys_hpp
#define Opersys_hpp

#include <stdio.h>

class processClass{
public:
    
    string name;    // Process Name.
    int runtime;   //  Total Run Time
    int Memory;   //   Memory
    int cycles;  //    Number od cycles to run the process.     - CALCULATE -
    int inout;  //     simulator reads in this command.         - I/O -
    int yield; //      pauses the running process               - YIELD -
    int out;  //       print out a message to the screen        - OUT -
    
    string processState; // Process State: New, Running, waiting, ready, Terminated.
    
    processClass();
    
    
    
};


class scheduler {
    
    
    
    
    
};


void openingcommand();
void printHelp();
void AddProcess(processClass *newProcess);
void LoadFile(processClass *newProcess);






#endif /* Opersys_hpp */
