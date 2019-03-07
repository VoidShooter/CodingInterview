#include <iostream>
#include <vector>
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
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> allpath;
        vector<int> path;
        if(root)
            FindPath(root, expectNumber, allpath, path);
        return allpath;
    }
private:
    void FindPath(TreeNode* root, int left, vector<vector<int>>& allpath, vector<int>& path){
        path.push_back(root->val);
        if(left-root->val==0&&!root->left&&!root->right)
            allpath.push_back(path);
        else{
            if(root->left)
                FindPath(root->left, left-root->val);
            if(root->right)
                FindPath(root->right, left-root->val);
        }
        path.pop_back();
    }
};
//      8
//     8 7
//    9 2
//   6 5
int main() {
    TreeNode t1(8), t2(8), t3(7), t4(9), t5(2), t6(6), t7(5), t8(1), t9(2);
    t1.left = &t2; t1.right = &t3;
    t2.left = &t4; t2.right = &t5;
    t4.left = &t6; t4.right = &t7;
    t3.left = &t8; t8.right = &t9;
    vector<vector<int>> output = Solution().FindPath(&t1, 18);
    return 0;
}