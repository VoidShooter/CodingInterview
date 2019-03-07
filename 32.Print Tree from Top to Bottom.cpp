#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> output;
        if(root==nullptr)
            return output;
        dequeAid.push_back(root);
        while(!dequeAid.empty()){
            TreeNode* node=dequeAid.front();
            dequeAid.pop_front();
            output.push_back(node->val);
            if(node->left!=nullptr)
                dequeAid.push_back(node->left);
            if(node->right!=nullptr)
                dequeAid.push_back(node->right);
        }
        return output;
    }
private:
    deque<TreeNode*> dequeAid;
};
int main() {
    TreeNode t1(8), t2(8), t3(7), t4(9), t5(2);
    t1.left = &t2; t1.right = &t3;
    t2.left = &t4; t2.right = &t5;
    vector<int> output = Solution().PrintFromTopToBottom(&t1);
    for(auto it = output.begin();it!=output.end();it++)
        cout<<*it<<endl;

}