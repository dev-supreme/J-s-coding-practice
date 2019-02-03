//
//  main.cpp
//  dailyPractice2forC++
//
//  Created by Jay on 03/02/2019.
//  Copyright © 2019 Jay. All rights reserved.
//
//


#include <iostream>
using namespace std;


void push(int);
int pop(void);
const int STACK_SIZE = 5;
int stack[STACK_SIZE] = {0, };
int top = -1;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    push(11);
    push(22);
    pop();
    pop();
    pop();
    push(33);
    push(44);
    push(55);
    push(66);
    pop();

    
  
    return 0;
}


void push(int data)
{
    if (top == STACK_SIZE - 1)
    {
        cout << "overflow! " << endl;
        return;
    }
    else
    {
        cout << "push() " << "data: " << data << " top: " << top + 1 << endl;
        stack[++top] = data;
    }
}


int pop(void)
{
    int data = 0;
    if (top == -1)
    {
        cout << "underflow! " << endl;
        return 0;
    }
    else
    {
        cout << "pop() " << "data: "<< data << " top " << top << endl;
        data = stack[top--];
        return data;
    }
}
