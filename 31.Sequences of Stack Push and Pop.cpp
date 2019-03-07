#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(popV.size()==0)
            return true;
        vector<int>::iterator itPop = popV.begin();
        vector<int>::iterator itPush = pushV.begin();
        while(itPop!=popV.end()){
            if(stackAid.empty()||stackAid.top()!=*itPop){
                if(itPush==pushV.end())
                    return false;
                stackAid.push(*itPush);
                itPush++;
            }else{
                stackAid.pop();
                itPop++;
            }
        }
        return true;
    }
private:
    stack<int> stackAid;
};
int main() {
    vector<int> pushV={1,2,3,4,5};
    vector<int> popV={4,5,3,2,1};
    cout<<Solution().IsPopOrder(pushV, popV);

}