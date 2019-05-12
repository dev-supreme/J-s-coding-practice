//
//  CCoffeeMake.cpp
//  Starbucks
//
//  Created by Jay on 12/05/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#include "CCoffeeMake.hpp"


void CCoffeeMake::SetIngredient(int espresso, int water, int steamedMilk, int milkFroth, bool caramelSyrup, bool whippedCream)
{
    this->espresso = espresso;
    this->water = water;
    this->steamedMilk = steamedMilk;
    this->milkFroth = milkFroth;
    this->caramelSyrup = caramelSyrup;
    this->whippedCream = whippedCream;
}

void CCoffeeMake::ServeCoffee(void)
{
    cout << "espresso: " << espresso << endl;
    cout << "water: " << water << endl;
    cout << "steamedMilk: " << steamedMilk << endl;
    cout << "milkFroth: " << milkFroth << endl;
    cout << "caramelSyrup: " << caramelSyrup << endl;
    cout << "whippedCream: " << whippedCream << endl;
    
    cout << "Your coffee has been served. " << endl;
}



