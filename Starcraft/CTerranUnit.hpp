//
//  CTerranUnit.hpp
//  dailyPracticeforC++2
//
//  Created by Jay on 14/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#ifndef CTerranUnit_hpp
#define CTerranUnit_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
#include "CUnitStatus.hpp"



class CTerranUnit
{
    CUnitStatus status;
    
public:
    
    CTerranUnit();
    ~CTerranUnit();
    
    CUnitStatus& getStatus()
    {
        return status;
    }
    virtual void Move();
    virtual void Attack();
    virtual void Stop();
    virtual void Patrol();

    virtual void Hold();
};




#endif /* CTerranUnit_hpp */
