#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array;
        stack<ListNode*> nodes;

        ListNode* pNode = head;
        while(pNode!= nullptr){
            nodes.push(pNode);
            pNode = pNode->next;
        }
        while (!nodes.empty()){
            pNode = nodes.top();
            array.push_back(pNode->val);
            nodes.pop();
        }
        return array;
    }
};
int main() {
    ListNode n1(1), n2(2), n3(3);
    n1.next = &n2;
    n2.next = &n3;
    vector<int> array= Solution().printListFromTailToHead(&n1);
    cout<<array[0]<<array[1]<<array[2];
    return 0;
}