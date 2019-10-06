//
//  Opersys.cpp
//  OS-Tester
//
//  Created by Nosayba Hamada on 10/5/19.
//  Copyright © 2019 Nosayba Hamada. All rights reserved.
//





#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include "Opersys.hpp"


using namespace std;


    string name;    // Process Name.
    int runtime;   //  Total Run Time
    int Memory;   //   Memory
    int cycles;  //    Number od cycles to run the process.     - CALCULATE -
    int inout;  //     simulator reads in this command.         - I/O -
    int yield; //      pauses the running process               - YIELD -
    int out;  //       print out a message to the screen        - OUT -

    string processState; // Process State: New, Running, waiting, ready, Terminated
    
    processClass::processClass(){ processState = "NEW"; }




typedef map<string , processClass>processMap;
processMap process;



void openingcommand(){

    cout << "INITIALIZING OPERTING SYSTEM.."<< endl << endl;
    cout << "Type Help to view the lsit of commands to use this OS." << endl;

}

void printHelp() {
    
    //Help command
    cout << "For help menu, type: Help" << endl;
    
    //Add process
    cout << "To add a process, type: Add Process" << endl;
    
    //Load File
    cout << "To load a file, type: Load File" << endl;
    
    //exit
    cout << "To exit, type: EXIT" << endl;
    
//ADD MORE COMMAND LATER

}

void AddProcess( processClass *newProcess) {
    
    string input;
    bool reading = true;
    
    cout << "To manuly add a process, type:" <<endl;
    cout << "Name: x            -- To add process name"<< endl << "Total runtime: x   -- To add Total run time of process" << endl;
    cout << "Memory: x          -- To add Memory Size" << endl << "CALCULATE: x       -- To add number of cycles" <<endl;
    cout << "I/O: x             -- To add I/O commands" << endl << "YIELD: x           -- To add yield commands" <<endl;
    cout << "OUT: x             -- To add OUT message commands" << endl << "EXE: x             -- To load commands" <<endl;
    
    while(reading) {
    cin >> input;
    
    //Get process Name
    if (input == "Name"){ cin >> input; newProcess->name = input; cout << newProcess->name << endl; }
    if (input == "Total runtime") { cin >> input; cin >> input; newProcess->runtime = stoi(input); cout << newProcess->runtime << endl; }
    if (input == "CALCULATE") { cin >> input; newProcess->cycles = stoi(input); cout << newProcess->cycles << endl; }
    if (input == "I/O") { cin >> input; newProcess->inout = stoi(input); cout << newProcess->inout << endl; }
    if (input == "YIELD") { cin >> input; newProcess->yield = stoi(input); cout << newProcess->yield << endl; }
    if (input == "OUT") { cin >> input; newProcess->out = stoi(input); cout << newProcess->out << endl; }
    if (input == "Memory") { cin >> input; newProcess->Memory = stoi(input); cout << newProcess->Memory << endl; }
    if (input == "EXE") { cout << "Loading prcoess into OS" << endl; reading  = false;}
    
    //else cout << "TYPE VALID COMMAD" <<endl;
    }
    
}


// Load a file to add a new process.
void LoadFile(processClass *newProcess){
    
string fileName;
string input;
ifstream fin;
ofstream fout;
bool reading = true;



    
//Get File Name
    cout << "File Name: " << endl;
    cin >> fileName;
    
//Get File Content
    fin.open(fileName);
    if(fin.fail()) { cout << "File failed to open." << endl; }

    
    while (reading) {
        fin >> input;
        
       //Get process Name
        if (input == "Name:"){ getline(fin,input); newProcess->name = input; cout << newProcess->name << endl; }
        
        if (input == "Total") { fin >> input; fin >> input; newProcess->runtime = stoi(input); cout << newProcess->runtime << endl; }
        if (input == "CALCULATE") { fin >> input; newProcess->cycles = stoi(input); cout << newProcess->cycles << endl; }
        if (input == "I/O") { fin >> input; newProcess->inout = stoi(input); cout << newProcess->inout << endl; }
        if (input == "YIELD") { fin >> input; newProcess->yield = stoi(input); cout << newProcess->yield << endl; }
        if (input == "OUT") { fin >> input; newProcess->out = stoi(input); cout << newProcess->out << endl; }
        if (input == "Memory:") { fin >> input; newProcess->Memory = stoi(input); cout << newProcess->Memory << endl; }
        if (input == "EXE") { cout << input << endl; reading = false; }
        
    }
}


