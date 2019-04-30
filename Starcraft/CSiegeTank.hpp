//
//  CSiegeTack.hpp
//  dailyPracticeforC++2
//
//  Created by Jay on 14/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#ifndef CSiegeTack_hpp
#define CSiegeTack_hpp


#include "CTerranUnit.hpp"
#include "CRangeAttack.hpp"

class CSiegeTank : public CTerranUnit
{
private:
    CRangeAttack range;
    
    
public:

    

    void Attack();

};

#endif /* CSiegeTack_hpp */
