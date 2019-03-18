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
	int TreeDepth(TreeNode* pRoot){
		if (!pRoot)
			return 0;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return left > right ? left + 1 : right + 1;
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
	cout << Solution().TreeDepth(&t1);
}
