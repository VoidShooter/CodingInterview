#include <iostream>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(!pHead)
            return nullptr;
        RandomListNode* pNode = pHead;
        while(pNode){
            RandomListNode* pTemp=pNode->next;
            RandomListNode* pDouble = new RandomListNode(pNode->label);
            pNode->next = pDouble;
            pDouble->next = pTemp;
            pNode = pTemp;
        }
        pNode = pHead;
        RandomListNode* pOutput = pHead->next;
        while(pNode){
            if(pNode->random!=nullptr){
                pNode->next->random = pNode->random->next;
            }
            pNode = pNode->next->next;
        }
        pNode = pHead;
        while(pNode){
            RandomListNode* pTemp = pNode->next;
            if(pTemp){
                pNode->next = pTemp->next;
            }
            pNode = pTemp;
        }
        return pOutput;
    }
};
int main() {
    RandomListNode n1(1), n2(2), n3(3);
    n1.next = &n2; n2.next = &n3;
    n1.random = &n3;
    RandomListNode* copy = Solution().Clone(&n1);
    return 0;
}