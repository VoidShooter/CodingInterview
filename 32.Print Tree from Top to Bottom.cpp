#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    void PrintFromTopToBottomZ(TreeNode* root) {
        if(root==nullptr)
            return;
        dequeAid.push_back(root);
        int thisStage = 1;
        int nextStage = 0;
        int zFlag = 0;
        while(!dequeAid.empty()){
            TreeNode* node=dequeAid.front();
            dequeAid.pop_front();
            if(zFlag)
                stackAid.push(node->val);
            else
                cout<<node->val<<' ';
            thisStage--;
            if(node->left!=nullptr){
                dequeAid.push_back(node->left);
                nextStage++;
            }
            if(node->right!=nullptr){
                dequeAid.push_back(node->right);
                nextStage++;
            }
            if(thisStage==0){
                if(zFlag){
                    while(!stackAid.empty()){
                        cout<<stackAid.top()<<' ';
                        stackAid.pop();
                    }
                }
                thisStage = nextStage;
                nextStage = 0;
                cout<<endl;
                zFlag ^= 1;
            }
        }
    }

private:
    deque<TreeNode*> dequeAid;
    stack<int> stackAid;
};
//      8
//     8 7
//    9 2
//   6 5
int main() {
    TreeNode t1(8), t2(8), t3(7), t4(9), t5(2), t6(6), t7(5);
    t1.left = &t2; t1.right = &t3;
    t2.left = &t4; t2.right = &t5;
    t4.left = &t6; t4.right = &t7;
    vector<int> output = Solution().PrintFromTopToBottom(&t1);
    for(auto it = output.begin();it!=output.end();it++)
        cout<<*it<<endl;
    Solution().PrintFromTopToBottomZ(&t1);

}
