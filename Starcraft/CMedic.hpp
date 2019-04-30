//
//  CMedic.hpp
//  dailyPracticeforC++2
//
//  Created by Jay on 28/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#ifndef CMedic_hpp
#define CMedic_hpp

#include <stdio.h>
#include "CTerranUnit.hpp"


class CMedic : public CTerranUnit
{
    
    
public:
    CMedic(void);
    ~CMedic(void);
    
    
    void Heal(void);
    
};


#endif /* CMedic_hpp */
