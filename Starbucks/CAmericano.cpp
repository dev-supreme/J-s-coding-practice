//
//  CAmericano.cpp
//  Starbucks
//
//  Created by Jay on 12/05/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#include "CAmericano.hpp"

void CAmericano::SetCoffee()
{
    SetIngredient(espresso, water, 0, 0, false, false);
    ServeCoffee();
}
