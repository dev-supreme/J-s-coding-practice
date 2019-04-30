//
//  CDropship.hpp
//  dailyPracticeforC++2
//
//  Created by Jay on 28/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#ifndef CDropship_hpp
#define CDropship_hpp

#include <stdio.h>
#include "CTerranUnit.hpp"

class CDropship : public CTerranUnit
{
    
public:
    CDropship(void);
    ~CDropship(void);
    
    void Load(void);
    void Unload(void);
    void Attack(void);
   
    
    
    
};




#endif /* CDropship_hpp */
