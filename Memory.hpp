//
//  Memory.hpp
//  OS-Tester
//
//  Created by Nosayba Hamada on 11/10/19.
//  Copyright © 2019 Nosayba Hamada. All rights reserved.
//

#ifndef Memory_hpp
#define Memory_hpp

#include <stdio.h>
using namespace std;

#endif /* Memory_hpp */


class MemoryClass {
public:
    
    int MemorySize;
    int MemoryUsed = 0;
    int processSize;


     MemoryClass();
     MemoryClass(int Size);
    
    int  getMemorySize();
    void setSize(int size);
    int  getMemoryUsed();
    void allocation(int pSize);
    

    
    
};
