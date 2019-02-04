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

typedef struct node
{
    int nData;
    node* pPrev;
}node;


node* top;
const int STACK_SIZE = 5;
int currentStackSize = 0;


void push(int, node**);
int pop(node**);
//int popAllStack(void);



int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    push(11, &top);
    push(22, &top);
    pop(&top);
    pop(&top);
    pop(&top);
    push(33, &top);
    push(44, &top);
    push(55, &top);
    push(66, &top);
    pop(&top);
    push(77, &top);
    push(88, &top);
    push(99, &top);
    push(111, &top);
  
    return 0;
}


void push(int data, node** topAddr)
{
    node* top = *topAddr;
    node* newNode = (node*)malloc(sizeof(node));
    newNode->nData = data;
    newNode->pPrev = NULL;
    
    
    
    if (currentStackSize >= STACK_SIZE)
    {
        cout << "push(" << data << "): " << "overflow! " << endl;
        return;
    }
    else if(currentStackSize == 0)
    {
        *topAddr = newNode;
        currentStackSize++;
    }
    else
    {
        newNode->pPrev = top;
        *topAddr = newNode;
        currentStackSize++;
    }
    
    cout << "push(" << data << "), " << "stackSize: " << currentStackSize << endl;
    
}


int pop(node** topAddr)
{
    node* top = *topAddr;
    int data = 0;
    if (currentStackSize <= 0)
    {
        cout << "pop(): underflow! " << endl;
        return 0;
    }
    else
    {
        data = top->nData;
        *topAddr = top->pPrev;
        currentStackSize--;
        cout << "pop(): " << data << " stackSize: " << currentStackSize << endl;
        
        return data;
    }
    
}
