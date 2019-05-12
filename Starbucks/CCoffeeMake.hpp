//
//  CCoffeeMake.hpp
//  Starbucks
//
//  Created by Jay on 12/05/2019.
//  Copyright © 2019 Jay. All rights reserved.
//
//  모든 커피 메뉴들은 반드시 커피메이크 클래스를 상속시켜서 사용한다.

#ifndef CCoffeeMake_hpp
#define CCoffeeMake_hpp

#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct recipe
{
    typedef int espresso;        // 에스프레소 샷.
    typedef int water;           // 물.
    typedef int steamedMilk;     // 끓인우유.
    typedef int milkFroth;       // 우유거품.
    
    typedef bool caramelSyrup;   // 카라멜시럽.
    typedef bool whippedCream;   // 휘핑크림.
    
    
    espresso eUnit;
    water wUnit;
    steamedMilk sUnit;
    milkFroth mUnit;
    caramelSyrup cBool;
    whippedCream wcUnit;
    
    recipe()
    {
        eUnit = 0;
        wUnit = 0;
        sUnit = 0;
        mUnit = 0;
        cBool = 0;
        wcUnit = 0;
    }
}recipe;




class CCoffeeMake
{
private:
    // 잔 최대 크기 10을 채우는 비율을 입력한다.
    
    int espresso;       // 에스프레소 샷.
    int water;          // 물.
    int steamedMilk;    // 끓인우유.
    int milkFroth;      // 우유거품.

    bool caramelSyrup;  // 카라멜시럽.
    bool whippedCream;  // 휘핑크림.
    

public:

    void SetIngredient(int espresso, int water, int steamedMilk, int milkFroth, bool caramelSyrup, bool whippedCream);
    
    
    void ServeCoffee(void);
};





#endif /* CCoffeeMake_hpp */
