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
    void Mirror(TreeNode *pRoot) {
        if(pRoot!= nullptr){
            TreeNode* temp;
            temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
            if(pRoot->left!= nullptr)
                Mirror(pRoot->left);
            if(pRoot->right!= nullptr)
                Mirror(pRoot->right);
        }
    }
};
//      8
//     8 7
//    9 2
int main() {
    TreeNode t1(8), t2(8), t3(7), t4(9), t5(2);
    t1.left = &t2; t1.right = &t3;
    t2.left = &t4; t2.right = &t5;
    Solution().Mirror(&t1);
    cout<<t1.left->val;
    return 0;
}