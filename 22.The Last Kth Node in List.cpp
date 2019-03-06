#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k == 0) return nullptr;
        ListNode* pHead = pListHead;
        for(int i=1;i<k;i++){
            if(pHead->next== nullptr) return nullptr;
            pHead = pHead->next;
        }
        ListNode* pTail = pListHead;
        while(pHead->next!=nullptr){
            pHead = pHead->next;
            pTail = pTail->next;
        }
        return pTail;
    }
};
int main() {
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    cout<<Solution().FindKthToTail(&n1,2)->val;
    return 0;
}