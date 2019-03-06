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
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        ListNode* meetingNode = MeetingNode(pHead);
        if(meetingNode== nullptr)
            return nullptr;
        int nodeNumber = 1;
        ListNode* tempNode = meetingNode;
        while(tempNode->next != meetingNode){
            tempNode = tempNode->next;
            nodeNumber++;
        }
        ListNode* headNode = pHead;
        ListNode* tailNode = pHead;
        for(int i = 0;i<nodeNumber;i++)
            headNode = headNode->next;
        while(headNode!=tailNode){
            headNode = headNode->next;
            tailNode = tailNode->next;
        }
        return headNode;
    }
private:
    ListNode* MeetingNode(ListNode* pHead){
        if(pHead==nullptr)
            return nullptr;
        ListNode* pSlow = pHead->next;
        if(pSlow==nullptr)
            return nullptr;
        ListNode* pFast = pSlow->next;
        while(pFast!=nullptr&&pSlow!= nullptr){
            if(pFast==pSlow)
                return pFast;
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast!= nullptr)
                pFast = pFast->next;
        }
        return nullptr;
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
    n7.next = &n2;
    cout<<Solution().EntryNodeOfLoop(&n1)->val;
    return 0;
}