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
#include "Opersys.hpp"
using namespace std;






int main(int argc, char* argv[]) {
    
    string command;
    bool   running = true;
    int processNum = 0;
    int PN;
    //typedef map<int , processClass>processMap;
    processClass process[10];
    
    
    
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
    if ((command == "Add Process") || (command == "add process") || (command == "ADD PROCESS")) { AddProcess( &process[processNum]); processNum++; }
    // If loading a file, instantiate and object for that process then load file
    if ((command == "Load File") || (command == "load file") || (command == "LOAD FILE")) { LoadFile( &process[processNum]); processNum++; }
    
    if ((command == "Exit") || (command == "EXIT") || (command == "exit")) {running = false;}
    
    if (command == "print") {cin >> PN; cout << process[PN].name << "  " << process[PN].Memory <<endl;}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        
    }
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}


























