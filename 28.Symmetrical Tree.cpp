#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot== nullptr)
            return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }
private:
    bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1== nullptr&&pRoot2== nullptr)
            return true;
        if(pRoot1== nullptr||pRoot2== nullptr)
            return false;
        if(pRoot1->val!=pRoot2->val)
            return false;

        return isSymmetrical(pRoot1->left, pRoot2->right)
               &&isSymmetrical(pRoot1->right, pRoot2->left);
    }
};
//      8
//    7   7
//   9 2 2 9
int main() {
    TreeNode t1(8), t2(7), t3(7), t4(9), t5(2), t6(2), t7(9);
    t1.left = &t2; t1.right = &t3;
    t2.left = &t4; t2.right = &t5;
    t3.left = &t6; t3.right = &t7;
    cout<<Solution().isSymmetrical(&t1);
    return 0;
}