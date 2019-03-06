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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* reverseHead = nullptr;
        ListNode* pPre = nullptr;
        ListNode* pNode = pHead;
        while(pNode!=nullptr){
            ListNode* pNext = pNode->next;
            if(pNext== nullptr)
                reverseHead = pNode;
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        return reverseHead;
    }
//    ListNode* ReverseList(ListNode* pHead) {
//        if(pHead== nullptr)
//            return nullptr;
//        ListNode* temp = nullptr;
//        ListNode* pLeft = pHead;
//        if(pLeft->next!= nullptr){
//            ListNode* pRight = pLeft->next;
//            while(pRight!= nullptr){
//                pLeft->next = temp;
//                temp = pLeft;
//                pLeft = pRight;
//                pRight = pRight->next;
//            }
//            pLeft->next = temp;
//            return pLeft;
//        }
//        return pHead;
//    }
};
int main() {
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    ListNode* headNode = Solution().ReverseList(&n1);
    while (headNode){
        cout<<headNode->val<<endl;
        headNode = headNode->next;
    }
    return 0;
}