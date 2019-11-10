//
//  Memory.cpp
//  OS-Tester
//
//  Created by Nosayba Hamada on 11/10/19.
//  Copyright © 2019 Nosayba Hamada. All rights reserved.
//

#include "Memory.hpp"

#include <iostream>
#include <fstream>
#include <string>

//Memory size: 4096 MB



MemoryClass::MemoryClass() { MemorySize = 4096; }; //constructor

MemoryClass::MemoryClass(int Size) { MemorySize = 4096; };

int MemoryClass::getMemorySize() { return MemorySize; }

void MemoryClass::setSize(int size) { processSize = size; }

int MemoryClass::getMemoryUsed() { return MemoryUsed; }



//availble memory

void MemoryClass::allocation( int pSize) {
    int temp = MemoryUsed;
    
    
    
    
    if ( (temp += pSize) <= MemorySize ) {
        cout << "MemorySize: " << MemorySize << endl;
        
        cout << "Memory: " << temp << endl;
        MemoryUsed += pSize;
        
        //return true;
    }
    
    else
        cout << "ERROR: Memory Full" << endl;
        //return false; 
    
}



//used memory




