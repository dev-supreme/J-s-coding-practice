//
//  CCafeLatte.cpp
//  Starbucks
//
//  Created by Jay on 12/05/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#include "CCafeLatte.hpp"

void CCafeLatte::SetCoffee()
{
    SetIngredient(espresso, 0, steamedMilk, milkFroth, false, false);
    ServeCoffee();
}
