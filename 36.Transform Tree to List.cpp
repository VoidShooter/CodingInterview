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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return nullptr;
        TreeNode* pLeft = Convert(pRootOfTree->left);
        TreeNode* pRight = Convert(pRootOfTree->right);
        TreeNode* pRootHead = pRootOfTree;
        if(pLeft){
            pRootHead = pLeft;
            TreeNode* pTemp=pLeft;
            while(pTemp->right) pTemp = pTemp->right;
            pTemp->right = pRootOfTree;
            pRootOfTree->left = pTemp;
        }
        if(pRight){
            pRootOfTree->right = pRight;
            pRight->left = pRootOfTree;
        }
        return pRootHead;
    }
};
//      10
//     6  14
//    4 8
int main() {
    TreeNode t1(10), t2(6), t3(14), t4(4), t5(8);
    t1.left = &t2; t1.right = &t3;
    t2.left = &t4; t2.right = &t5;
    TreeNode* output = Solution().Convert(&t1);
    while(output){
        cout<<output->val;
        output = output->right;
    }
}