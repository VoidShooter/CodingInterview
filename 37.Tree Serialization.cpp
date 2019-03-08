#include <iostream>
#include <deque>
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
    char* Serialize(TreeNode *root) {
        string s;
        if(!root)
            return nullptr;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                if(q.front()){
                    q.push_back(q.front()->left);
                    q.push_back(q.front()->right);
                    s += to_string(q.front()->val) + ' ';
                }else{
                    s += '# ';
                }
                q.pop_front();
            }
        }
        char* chr = strdup(s.c_str());
        return chr;
    }
    TreeNode* Deserialize(char *str) {
        if (!str)
            return nullptr;
        int k = 0;
        auto ret = nextNode(str, k);
        deque<TreeNode*> q;
        q.push_back(ret);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                q.front()->left = nextNode(str, k);
                q.front()->right = nextNode(str, k);
                if (q.front()->left)
                    q.push_back(q.front()->left);
                if (q.front()->right)
                    q.push_back(q.front()->right);
                q.pop_front();
            }
        }
        return ret;
    }
    TreeNode* nextNode(char *str,int &i) {
        string s;
        while (str[i] != '\0'&&str[i] != ' ') {
            if (str[i] == '#') {
                i += 2;
                return nullptr;
            }
            s += str[i];
            i++;
        }
        if (str[i] == ' ')
            i++;
        if (!s.empty())
            return new TreeNode(stoi(s));
        return nullptr;
    }
};
//      10
//     6  14
//    4 8
int main() {
    TreeNode t1(10), t2(6), t3(14), t4(4), t5(8);
    t1.left = &t2; t1.right = &t3;
    t2.left = &t4; t2.right = &t5;
    char* serialize = Solution().Serialize(&t1);
    TreeNode* deserialize = Solution().Deserialize(serialize);
}