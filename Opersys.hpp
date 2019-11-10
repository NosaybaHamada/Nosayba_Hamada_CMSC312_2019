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
#include <queue>
#include <deque>

#include "Memory.hpp"

using namespace std;



#ifndef Opersys_hpp
#define Opersys_hpp

#include <stdio.h>

class processClass{
public:
    
    string name;    // Process Name.
    int runtime;   //  Total Run Time
    int Memory;   //   Memory
    int cycles;  //    Number of cycles to run the process.     - CALCULATE -
    int inout;  //     simulator reads in this command.         - I/O -
    int yield; //      pauses the running process               - YIELD -
    int out;  //       print out a message to the screen        - OUT -
    
    int procNum; //Process Number
    int BT;     // Burst Time for process
    
    string processState; // Process State: New, Running, waiting, ready, Terminated.
    
     processClass();
void printProcess();
    
    
};

//Process Scheduler - using round robin
class scheduler{
public:
    
    queue<processClass> CPU;
    
    scheduler();
    
    void pushProcess( processClass newProcess);  // Push a new process in queue
    void popProcess();  //  Pop process out
    void schedulerFunc();    //Do Scheudling things
    void processState(processClass process);
    
    
    
};




void openingcommand();
void printHelp();
void AddProcess(processClass *newProcess, int processNum, MemoryClass *Memory);
void LoadFile(processClass *newProcess, int prcoessNum, MemoryClass *Memory);






#endif /* Opersys_hpp */
