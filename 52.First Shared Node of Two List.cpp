#include <iostream>
#include<vector>
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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1||!pHead2)
			return nullptr;
		int len1 = 0, len2 = 0;
		ListNode*p1 = pHead1, *p2 = pHead2;
		while (p1->next != nullptr) {
			len1++;
			p1 = p1->next;
		}
		while (p2->next != nullptr) {
			len2++;
			p2 = p2->next;
		}
		ListNode* pLong = len1 >= len2 ? pHead1 : pHead2;
		ListNode* pShort = len1 <= len2 ? pHead1 : pHead2;
		int dis = len1 >= len2 ? len1 - len2 : len2 - len1;
		for (int i = 0; i < dis; i++)
			pLong = pLong->next;
		while (pLong&&pShort){
			if (pLong == pShort)
				return pLong;
			pLong = pLong->next;
			pShort = pShort->next;
		}
		return nullptr;
	}
};
int main() {
	ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
	n1.next = &n2; n2.next = &n3; n3.next = &n6;
	                         n4.next = &n5; n5.next = &n6; n6.next = &n7;
	ListNode* result = Solution().FindFirstCommonNode(&n1,&n4);
	cout << result->val;
}
