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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* nodeHead=nullptr;
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2== nullptr)
            return pHead1;
        if(pHead1->val>pHead2->val){
            nodeHead = pHead2;
            pHead2->next = Merge(pHead1, pHead2->next);
        } else{
            nodeHead = pHead1;
            pHead1->next = Merge(pHead1->next, pHead2);
        }
        return nodeHead;
    }
};
int main() {
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.next = &n3;
    n2.next = &n4;
    n3.next = &n5;
    n4.next = &n6;

    ListNode* headNode = Solution().Merge(&n1, &n2);
    while (headNode){
        cout<<headNode->val<<endl;
        headNode = headNode->next;
    }
    return 0;
}