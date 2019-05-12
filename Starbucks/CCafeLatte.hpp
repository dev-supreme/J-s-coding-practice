//
//  CCafeLatte.hpp
//  Starbucks
//
//  Created by Jay on 12/05/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#ifndef CCafeLatte_hpp
#define CCafeLatte_hpp

#include "CCoffeeMake.hpp"


class CCafeLatte : CCoffeeMake
{
    int espresso = 3;       // 에스프레소 샷.
    int steamedMilk = 5;    // 끓인우유.
    int milkFroth = 2;      // 우유거품.

    
public:
    
    
    void SetCoffee();
};


#endif /* CCafeLatte_hpp */
