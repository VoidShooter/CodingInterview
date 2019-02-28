#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
void Link(TreeLinkNode& parent, TreeLinkNode& son, char typeSon){
    if (typeSon=='L'){
        parent.left=&son;
        son.next=&parent;
    }else{
        parent.right=&son;
        son.next=&parent;
    }
}
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        TreeLinkNode* pTree;
        if(pNode->right== nullptr&&pNode->next!= nullptr){ //up
            pTree = pNode;
            while (pTree->next!= nullptr){
                if(pTree->next->left==pTree) return pTree->next;
                pTree=pTree->next;
            }
        }else if(pNode->right!= nullptr){  //down
            pTree=pNode->right;
            while (pTree->left!= nullptr){
                pTree = pTree->left;
            }
            return  pTree;
        }
        return nullptr;
    }
};
//   1
// 2   3
//4 5 6 7    4251637
int main() {
    TreeLinkNode t1(1), t2(2), t3(3), t4(4), t5(5), t6(6), t7(7);
    Link(t1,t2,'L');Link(t1,t3,'R');
    Link(t2,t4,'L');Link(t2,t5,'R');
    Link(t3,t6,'L');Link(t3,t7,'R');
    cout<<Solution().GetNext(&t7)->val;
    return 0;
}