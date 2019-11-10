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
#include <queue>
#include <deque>
#include "Opersys.hpp"
//#include "Memory.hpp"


using namespace std;




processClass::processClass(){ processState = "NEW"; }

void processClass::printProcess(){
    cout << "Name: " << name << endl << "Process Number: " << procNum << endl <<"Total runtime: " << runtime << endl;
    cout << "Memory: " << Memory << endl << "Process State: " << processState <<endl;
    }





                                    /*    SCHEDULER CLASS */

     scheduler::scheduler(){ }

void scheduler::pushProcess( processClass newProcess){   CPU.push(newProcess);  }
void scheduler::popProcess(){ CPU.pop(); }
void scheduler::processState(processClass process) { string state; }



void scheduler::schedulerFunc(){
    
    int Q = 20; //Quantum
    size_t size = CPU.size();
    int currentRunning;
    processClass currentProcess, tempProcess;
    bool DONE = true;
    
    
    
    
    currentProcess = CPU.front();  // + CHANGE STATE TO READY
    currentRunning = currentProcess.cycles;
    
    //cout << "FIRST: "<<currentProcess.name << endl << "BT: " << currentRunning <<endl;
    
    while(DONE){
        
        
    if(CPU.empty()) { cout << endl <<"EMPTY CPU" << endl; DONE = false;}
    if(!CPU.empty()) {
        
        cout << "Currently running: " << currentProcess.name <<endl;
        
        for ( int i = 0; i < Q; i++) {
            currentRunning--;  cout << "processor BT: " << currentRunning << " ";
            if (currentRunning == 0) break;  /* + CHANGE STATE TO RUN */
            
        }
        
        if (currentRunning == 0) {
            popProcess();
            if (CPU.empty()){DONE = true;}
            else { currentProcess = CPU.front();} currentRunning = currentProcess.BT;}
        
        else {
        cout << endl << "swaping process" <<endl;
        tempProcess = CPU.front();
        tempProcess.BT = currentRunning;
        popProcess();
        pushProcess(tempProcess); // + CHANGE STATE TO WAITING
     
        currentProcess = CPU.front();
        currentRunning = currentProcess.BT;
        //cout << currentProcess.name << endl << "BT: " << currentRunning <<endl;
        
            if (currentRunning <= 0) { popProcess(); }
        }
    
    }
    
     size = CPU.size();
    
    //cout << "SIZE of QUEUE: " <<  size << endl;
    }
}










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
    
    cout << "To view process information, type: print process." <<endl;
    
    cout << "To view CPU, type: print Q." <<endl;
    
    cout << "To view Used Memory: View used Memory" << endl;
//ADD MORE COMMAND LATER

}

void AddProcess( processClass *newProcess, int prcoessNum, MemoryClass *Memory) {
    
    string input;
    bool reading = true;
    
    
    cout << "To manuly add a process, type:" <<endl;
    cout << "Name: x            -- To add process name"<< endl << "Total runtime: x   -- To add Total run time of process" << endl;
    cout << "Memory: x          -- To add Memory Size" << endl << "CALCULATE: x       -- To add number of cycles" <<endl;
    cout << "I/O: x             -- To add I/O commands" << endl << "YIELD: x           -- To add yield commands" <<endl;
    cout << "OUT: x             -- To add OUT message commands" << endl << "EXE: x             -- To load commands" <<endl;
    
    
    
    while(reading) {
    cin >> input;
    
    
        if (input == "Name"){ cin >> input; newProcess->name = input;  }
        if (input == "Total runtime") { cin >> input; cin >> input; newProcess->runtime = stoi(input);}
        if (input == "CALCULATE") { cin >> input; newProcess->cycles = stoi(input); newProcess->BT = stoi(input); }
        if (input == "I/O") { cin >> input; newProcess->inout = stoi(input); }
        if (input == "YIELD") { cin >> input; newProcess->yield = stoi(input);}
        if (input == "OUT") { cin >> input; newProcess->out = stoi(input); }
        if (input == "Memory") { cin >> input; newProcess->Memory = stoi(input); Memory->allocation(stoi(input));  }
        if (input == "EXE") { cout << "Loading prcoess into OS. Process Number is: " << prcoessNum << endl; reading  = false;}
    
    //else cout << "TYPE VALID COMMAD" <<endl;
    }
    
}


// Load a file to add a new process.
void LoadFile(processClass *newProcess, int prcoessNum, MemoryClass *Memory){
    
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

    cout << "LOADING FILE" <<endl;
    
    while (reading) {
        fin >> input;
        cout << "..." << endl;
       //Get process Name
        if (input == "Name:"){ getline(fin,input); newProcess->name = input; }
        
            if (input == "Total") { fin >> input; fin >> input; newProcess->runtime = stoi(input); }
            if (input == "CALCULATE") { fin >> input; newProcess->cycles = stoi(input); newProcess->BT = stoi(input);}
            if (input == "I/O") { fin >> input; newProcess->inout = stoi(input); }
            if (input == "YIELD") { fin >> input; newProcess->yield = stoi(input); }
            if (input == "OUT") { fin >> input; newProcess->out = stoi(input);}
            if (input == "Memory:") { fin >> input; newProcess->Memory = stoi(input); /*if (!Memory->allocation(stoi(input))) { cout << " ERROR: Memory is full" << endl; } */ Memory->allocation(stoi(input));}
        if (input == "EXE") { cout << "File loaded successfully, DONE. Process Number is: " << prcoessNum << endl; reading = false; }
        
    }
}


