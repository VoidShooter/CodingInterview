#include<vector>
#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* KthNode(TreeNode* hNode, unsigned int k) {
		if (!hNode)
			return nullptr;
		return KthNodeCore(hNode, k);
	}
private:
	TreeNode* KthNodeCore(TreeNode* hNode, unsigned int & k) {
		TreeNode* result = nullptr;
		if (hNode->left) {
			result = KthNodeCore(hNode->left, k);
		}
		if (!result) {
			if (k == 1)
				result = hNode;
			k--;
		}
		if (!result&&hNode->right)
			result = KthNodeCore(hNode->right, k);
		return result;
	}
};
//      6
//     4 7
//    2 5
//   1 3
int main() {
	TreeNode t1(6), t2(4), t3(7), t4(2), t5(5), t6(1), t7(3);
	t1.left = &t2; t1.right = &t3;
	t2.left = &t4; t2.right = &t5;
	t4.left = &t6; t4.right = &t7;
	cout << Solution().KthNode(&t1, 3)->val;
}
