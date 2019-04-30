//
//  CMarine.hpp
//  dailyPracticeforC++2
//
//  Created by Jay on 14/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

//#pragma once  비주얼스튜디오에서는 아래 전처리구문 대신 이 한줄로 대체.
#ifndef CMarine_hpp
#define CMarine_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
#include "CTerranUnit.hpp"
#include "CRangeAttack.hpp"
class CMarine : public CTerranUnit
{
private:
    CRangeAttack range;
    
    
public:

    void Stimpack();
    void Attack();
    
};




#endif /* CMarine_hpp */
