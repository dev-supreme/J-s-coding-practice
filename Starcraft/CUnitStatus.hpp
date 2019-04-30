//
//  CStatus.hpp
//  dailyPracticeforC++2
//
//  Created by Jay on 14/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#ifndef CUnitStatus_hpp
#define CUnitStatus_hpp
#include <stdio.h>
#include <iostream>
using namespace std;


enum
{
    AT_NORMAL,
    AT_EXPLOSION,
    AT_VIBE
};

enum
{
    UNIT_NORMAL,
    UNIT_SMALL,
    UNIT_LARGE
};

class CUnitStatus {
private:
    int HP_MAX;
    int HP;
    int AP;
    int DP;
    int AT_TYPE;
    int UNIT_TYPE;
    
public:
    
    CUnitStatus();
    ~CUnitStatus();
    
    void initialize(int hp_max, int ap, int dp, int at_type, int unit_type);
    void setHP(int hp);
    int getHP(void);
    void setAP(int ap);
    int getAP(void);
    void setDP(int dp);
    int getDP(void);
    void setAT_TYPE(int at_type);
    int getAT_TYPE(void);
    void DealDamage(int ap, int at_type);
    
};
#endif /* CStatus_hpp */
