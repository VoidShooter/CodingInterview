#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len=pre.size();
        if(len==0){
            return nullptr;
        }
        return reConstructBinaryTree(pre, 0, len-1, vin, 0, len-1);
    }
private:
    TreeNode* reConstructBinaryTree(vector<int> pre, int startPre, int endPre, vector<int> vin, int startVin, int endVin){
        if(startPre>endPre||startVin>endVin)
            return nullptr;
        TreeNode* root = new TreeNode(pre[startPre]);
        for(int i = startVin;i<=endVin;i++){
            if(vin[i]==pre[startPre]){
                root->left=reConstructBinaryTree(pre, startPre+1, startPre+i-startVin, vin, startVin, i-1);
                root->right=reConstructBinaryTree(pre, startPre+i-startVin+1, endPre, vin, i+1, endVin);
                break;
            }
        }
        return root;
    }
};
int main() {
    vector<int> pre={1,2,4,7,3,5,6,8};
    vector<int> in={4,7,2,1,5,3,8,6};
    TreeNode* p=Solution().reConstructBinaryTree(pre, in);
    cout<< p->val<<endl<<p->left->val<<endl<<p->right->val;
    return 0;
}