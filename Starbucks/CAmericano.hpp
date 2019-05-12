//
//  CAmericano.hpp
//  Starbucks
//
//  Created by Jay on 12/05/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#ifndef CAmericano_hpp
#define CAmericano_hpp

#include "CCoffeeMake.hpp"



class CAmericano : CCoffeeMake
{
    int espresso = 2;
    int water = 8;
    
    
public:
    
    void SetCoffee();
};

#endif /* CAmericano_hpp */
