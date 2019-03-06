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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1!= nullptr&&pRoot2!= nullptr){
            if(Equal(pRoot1->val, pRoot2->val))
                result = DoesTree1HaveTree2(pRoot1, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }

private:
    bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2== nullptr)
            return true;
        if(pRoot1== nullptr)
            return false;
        return Equal(pRoot1->val, pRoot2->val)
               &&DoesTree1HaveTree2(pRoot1->left, pRoot2->left)
               &&DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
    }
    bool Equal(double a, double b){
        if((a-b>-0.0000001)&&(a-b<0.0000001))
            return true;
        else
            return false;
    }
};
//      8
//     8 7
//    9 2
int main() {
    TreeNode t1(8), t2(8), t3(7), t4(9), t5(2), t6(8), t7(9), t8(2);
    t1.left = &t2; t1.right = &t3;
    t2.left = &t4; t2.right = &t5;
    t6.left = &t7; t6.right = &t8;
    cout<<Solution().HasSubtree(&t1, &t6);

    return 0;
}