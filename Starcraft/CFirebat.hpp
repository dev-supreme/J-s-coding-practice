//
//  CFirebat.hpp
//  dailyPracticeforC++2
//
//  Created by Jay on 14/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#ifndef CFirebat_hpp
#define CFirebat_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

#include "CTerranUnit.hpp"

class CFirebat : public CTerranUnit
{
private:

    
public:
    
    CFirebat();
    ~CFirebat();
    
    void Attack();
    void StimPack();
    

};


#endif /* CFirebat_hpp */
