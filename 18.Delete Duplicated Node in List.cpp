#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    explicit ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr) return nullptr;
        if(pHead->next== nullptr) return pHead;
        ListNode* current;

        if(pHead->next->val == pHead->val){
            current = pHead->next->next;
            while(current!= nullptr && current->val == pHead->val)
                current = current->next;
            return deleteDuplication(current);
        }else{
            current = pHead->next;
            pHead->next = deleteDuplication(current);
            return pHead;
        }
    }
};
int main() {
    ListNode n1(1), n2(2), n3(3), n4(3), n5(4), n6(4), n7(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    ListNode* pNode = Solution().deleteDuplication(&n1);
    while(pNode!= nullptr){
        cout<<pNode->val<<endl;
        pNode = pNode->next;
    }
    return 0;
}