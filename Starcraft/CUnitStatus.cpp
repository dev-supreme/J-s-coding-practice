//
//  CStatus.cpp
//  dailyPracticeforC++2
//
//  Created by Jay on 14/04/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#include "CUnitStatus.hpp"


CUnitStatus::CUnitStatus()
{
    
}
CUnitStatus::~CUnitStatus()
{
    
}

void CUnitStatus::initialize(int hp_max, int ap, int dp, int at_type, int unit_type)
{
    HP_MAX = hp_max;
    AP = ap;
    DP = dp;
    AT_TYPE = at_type;
    UNIT_TYPE = unit_type;
}

void CUnitStatus::setHP(int hp)
{
    HP = hp;
    
}
int CUnitStatus::getHP(void)
{
    return HP;
}
void CUnitStatus::setAP(int ap)
{
    AP = ap;
}
int CUnitStatus::getAP(void)
{
    return AP;
}
void CUnitStatus::setDP(int dp)
{
    DP = dp;
}
int CUnitStatus::getDP(void)
{
    return DP;
}
void CUnitStatus::setAT_TYPE(int at_type)
{
    AT_TYPE = at_type;
}
int CUnitStatus::getAT_TYPE(void)
{
    return AT_TYPE;
}
void CUnitStatus::DealDamage(int ap, int at_type)
{
    int damage = ap;
    if (AT_TYPE == AT_EXPLOSION && this->UNIT_TYPE == UNIT_LARGE)
    {
        damage *= 1.5;
    }
}

