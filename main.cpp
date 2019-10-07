//
//  main.cpp
//  OS-Tester
//
//  Created by Nosayba Hamada on 9/25/19.
//  Copyright © 2019 Nosayba Hamada. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <queue>
#include "Opersys.hpp"
using namespace std;






int main(int argc, char* argv[]) {
    
    string command;
    bool   running = true;
    int processNum = 0;
    int PN;
   
    processClass process[10];
    scheduler    CPU;
    
//Greetings
openingcommand();


while (running) {
    cin >> command;
    
   
    if ((command == "Help") || (command == "help") || (command == "HELP")) {running = false;}
    
    else { cout << "Please type Help to view the list of commands." << endl; }
    
    
    
}
    
    printHelp();
    running = true;
    
while (running){
    
    getline(cin,command);
    
    if ((command == "Help") || (command == "HELP") || (command == "help")) {printHelp(); }
    
    if ((command == "Add Process") || (command == "add process") || (command == "ADD PROCESS")) { process[processNum].procNum = processNum;
        cout << "Process number is: " << processNum << endl; AddProcess( &process[processNum], processNum); CPU.pushProcess( process[processNum]);  processNum++; }
    
    
    if ((command == "Load File") || (command == "load file") || (command == "LOAD FILE")) {  process[processNum].procNum = processNum;
        LoadFile( &process[processNum], processNum); CPU.pushProcess( process[processNum]);   processNum++;  }
    
    if ((command == "Exit") || (command == "EXIT") || (command == "exit")) {running = false;}
    
    if (command == "print process") { cout << "Processor number: " <<endl; cin >> PN; process[PN].printProcess();}
    
    if (command == "print Q") { CPU.schedulerFunc();}
    
    
    
    
  
        
    }
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}


























