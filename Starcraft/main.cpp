//
//  main.cpp
//  dailyPracticeforC++2
//
//  Created by Jay on 13/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#include <iostream>
using namespace std;

#include "CMarine.hpp"
#include "CFirebat.hpp"
#include "CSiegeTank.hpp"
#include "CDropship.hpp"
#include "CMedic.hpp"
#include "CWraith.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...

    
    CTerranUnit* unit[6];
    unit[0] = new CMarine();
    unit[1] = new CFirebat();
    unit[2] = new CSiegeTank();
    unit[3] = new CDropship();
    unit[4] = new CMedic();
    unit[5] = new CWraith();
    
    for (int i = 0; i < 6;  i++)
    {
        cout << i << endl;
        unit[i]->Move();
        unit[i]->Attack();
        cout << endl;
    }
    
//    unit[3]->Load();
//    unit[4]->Heal();
    
    
    
    return 0;
}
