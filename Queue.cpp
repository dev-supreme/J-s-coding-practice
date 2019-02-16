//
//  main.cpp
//  dailyPracticeforC++5
//
//  Created by Jay on 12/02/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

//  Queue 구현.


#include <iostream>
using namespace std;

typedef struct node
{
    int nData;
    node* pNext;
}node;


node* input;
node* output;
const int QUEUE_SIZE = 5;
int currentQueueSize = 0;


void push(int, node**, node**);
int pop(node**);



int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    push(11, &input, &output);
    push(22, &input, &output);
    pop(&output);
    pop(&output);
    pop(&output);
    push(33, &input, &output);
    push(44, &input, &output);
    push(55, &input, &output);
    push(66, &input, &output);
    pop(&output);
    push(77, &input, &output);
    push(88, &input, &output);
    push(99, &input, &output);
    push(111, &input, &output);
    
    return 0;
}


void push(int data, node** inputAddr, node** outputAddr)
{
    //    node* input = *inputAddr;
    node* output = *outputAddr;
    
    node* newNode = (node*)malloc(sizeof(node));
    newNode->nData = data;
    newNode->pNext = NULL;
    
    
    if (currentQueueSize >= QUEUE_SIZE)
    {
        cout << "push(" << data << "): overflow!" << endl;
        return;
    }
    else if (currentQueueSize <= 0) // 새 노드가 큐의 첫 노드라면,
    {
        *outputAddr = newNode;
        *inputAddr = newNode;
        
        currentQueueSize++;
        cout << "push(" << data << "), currentQueueSize: " << currentQueueSize << endl;
    }
    else
    {
        output->pNext = newNode;
        *inputAddr = newNode;
        
        currentQueueSize++;
        cout << "push(" << data << "), currentQueueSize: " << currentQueueSize << endl;
    }
}


int pop(node** outputAddr)
{
    int data = 0;
    node* output = *outputAddr;
    
    if (currentQueueSize <= 0)
    {
        cout << "pop(): underflow! " << endl;
        return 0;
    }
    else
    {
        data = output->nData;
        *outputAddr = output->pNext;
        currentQueueSize--;
        cout << "pop(): " << data << " currentQueueSize: " << currentQueueSize << endl;
        free(output);
    }
    return data;
    
}

