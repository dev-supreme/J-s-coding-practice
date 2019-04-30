//
//  CWraith.hpp
//  dailyPracticeforC++2
//
//  Created by Jay on 28/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#ifndef CWraith_hpp
#define CWraith_hpp

#include <stdio.h>
#include "CTerranUnit.hpp"
#include "CRangeAttack.hpp"

class CWraith : public CTerranUnit
{
    CRangeAttack rangeAttack;
    
public:
    CWraith(void);
    ~CWraith(void);
    
    void Attack(void);
    
};



#endif /* CWraith_hpp */
