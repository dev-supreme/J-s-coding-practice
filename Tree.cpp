//
//  main.cpp
//  dailyPractice2forC++
//
//  Created by Jay on 03/02/2019.
//  Copyright © 2019 Jay. All rights reserved.
//
//
//  트리 구현.
//
#include <iostream>
#include <vector>
using namespace std;


typedef struct node
{
    int nData;
    node* pLeft;
    node* pRight;
    node* pParent;

}node;


class treeInfo  // 트리 정보처리 클래스.
{
private:
    
    
public:
    int maxDepth;   // 가장 밑에 있는 원소의 깊이.
//    int maxNodeCount;   // 이진트리라는 전제 하에 존재 가능한 최대 노드 수. 아직 사용하지 않으므로 주석 처리.
    
    treeInfo(void)
    {
        maxDepth = 0;
//        maxNodeCount = 0;
    }
};

treeInfo oTreeInfo; // 전역변수로 선언된, 트리 정보관리 클래스 treeInfo의 객체.

node* root;



void insertNode(int, node**);
void showTree(node*);
void findNode(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
   
    return 0;
}

void insertNode(int data, node** root)
{
    
//    node* newNode = (node*)malloc(sizeof(node));
    node* newNode = new node;
    newNode->nData = data;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;
    newNode->pParent = NULL;
    node* pRoot = *root;
    int currentDepth = 0;

    
    if (pRoot == NULL)  // 새 노드가 트리의 첫 노드라면,
    {
        *root = newNode;
        oTreeInfo.maxDepth = 1;
    }
    else
    {
        while (pRoot != NULL)
        {
            if (newNode->nData > pRoot->nData)
            {
                if (pRoot->pRight == NULL)
                {
                    cout << pRoot->nData << ". " ;
                    pRoot->pRight = newNode;
                    newNode->pParent = pRoot;
                    currentDepth++;
                    cout << newNode->nData << "added. depth: " << currentDepth << endl;
                    if (oTreeInfo.maxDepth < currentDepth)
                    {
                        oTreeInfo.maxDepth = currentDepth;    // 최대 깊이 갱신.
                    }
                    break;
                }
                else
                {
                    cout << pRoot->nData << "<- " ;
                    pRoot = pRoot->pRight;
                    currentDepth++;
                }
            }
            else if (newNode->nData < pRoot->nData)
            {
                if (pRoot->pLeft == NULL)
                {
                    cout << pRoot->nData << ". " ;
                    pRoot->pLeft = newNode;
                    newNode->pParent = pRoot;
                    currentDepth++;
                    cout << newNode->nData << "added. depth: " << currentDepth << endl;
                    if (oTreeInfo.maxDepth < currentDepth)
                    {
                        oTreeInfo.maxDepth = currentDepth;    // 최대 깊이 갱신.
                    }
                    break;
                }
                else
                {
                    cout << pRoot->nData << "<- " ;
                    pRoot = pRoot->pLeft;
                    currentDepth++;
                }
            }
            else
            {
                cout << "이미 같은 값을 가진 노드가 존재합니다. " << endl;
//                free(newNode);
                delete newNode; // 노드 삭제. 주소값은 아직 지정하지도 않았으므로 따로 해제할 필요 없음.
                break;
            }
        }
    }
}

void showTree(node* root)
{
    // 일단 같은 계층인지 알아볼 수 있게만 구현.
    
    // 트리는 검색속도가 빠른게 장점 -> 왜 빠른가? 루프 없이 데이타값 크기 대조만 여러번 하면 되기 때문에. -> 숫자 대조를 이용해서 순회하자.
    
    vector< vector<node*> > vNode;
    node* p = root;


    
    int currentDepth = 1;
    int prevNodeData = 0;    // 이전에 찍었던 노드의 데이타.
    int tempData = 0;
    for (int i = 1; i < oTreeInfo.maxDepth; i++)    // i = 현재 순회하는 깊이.
    {
        // 현재 노드보다 큰 값을 가진 노드가 나올때까지 부모노드 혹은 부모노드의 오른쪽 노드로 이동한다? -> 이전에 찍었던 노드보다 같은 깊이이며 더 큰값을 가진 노드들 중 가장 왼쪽 노드로 이동시킨다. -> 오른쪽 끝 노드인지 아닌지 어떻게 알지? -> 노드 순회가 제대로 되고 있다는 전제 하에서 이전노드와 현재 노드가 값이 똑같으면 가장 오른쪽 노드?
        
 
        while (currentDepth < i)    // 해당 깊이내 가장 왼쪽 노드로 이동. currentData와의 비교와 좌우노드 존재 유무 등을 이용해서 같은 깊이의 전체 노드를 순회 가능하게 개선할 것.
        {
//            if (p->pLeft == NULL || prevNodeData > p->nData)
            if ( (p->pLeft == NULL && p->pRight == NULL) || (p->pLeft->nData <= tempData && p->pRight == NULL ) )
            {   // 양쪽 자식 노드가 둘 다 없거나, 왼쪽 자식노드가 임시 기준값보다 작으면서 오른쪽 자식노드가 없을때.
                tempData = p->nData;    // 임시 기준점을 이전 nData에서 현재 노드의 nData값으로 바꾼다.
                p = p->pParent;         // 부모 노드로 역행한다.
                currentDepth--;         // 역행했으므로 currentDepth도 역행.
                continue;
            }
//            else if (p->nData > p->pParent->nData || p->pParent->pRight == NULL)
            else if (p->nData < tempData || p->pLeft == NULL)
            {
                p = p->pRight;
                currentDepth++;
                continue;
            }
            else
            {
                p = p->pLeft;
                currentDepth++;
            }
        }
        prevNodeData = p->nData;    // 가장 마지막으로 출력한 노드의 데이타.
        vNode.at(i).push_back(p);   // 일단 진짜 출력대신 저장으로 대체.
//        p = p->pParent;             // 해당 노드의 이전 노드로 p를 옮긴다.
        p = root;                   // p를 원점으로.
        
//        if (condition) // 같은 깊이 내 모든 노드를 다 순회했다는 확실한 판정이 나올따까지 i를 뒤로 돌려서 계속 반복시킨다.
//        {
//            i--;
//            tempData = prevNodeData;
//        }
//        else  // 다 순회한게 확실하다면 tempData 초기화.
//        {
//            tempData = root->nData;
//        }
    }
    
    
    
    
    
    if (p->nData < p->pParent->nData)       // 현재 위치는 부모 노드의 왼쪽.
    {
        p = p->pParent->pRight;     // 부모 노드의 오른쪽 노드로 이동.
    }
    else if(p->nData > p->pParent->nData)   // 현재 위치는 부모 노드의 오른쪽.
    {
        p = p->pParent;     // 부모 노드로 이동.
    }
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
}

void findNode(void)
{
    
}
