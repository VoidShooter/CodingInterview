#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    void push(int value) {
        if(stackMin.empty()||value<stackMin.top())
            stackMin.push(value);
        else
            stackMin.push(stackMin.top());
        stackData.push(value);
    }
    void pop() {
        stackData.pop();
        stackMin.pop();
    }
    int top() {
        return stackData.top();
    }
    int min() {
        return stackMin.top();
    }

private:
    stack<int> stackData;
    stack<int> stackMin;
};
int main() {
    Solution a;
    a.push(1);
    cout<<a.top()<<' '<<a.min()<<endl;
    a.push(2);
    cout<<a.top()<<' '<<a.min()<<endl;
    a.pop();
    cout<<a.top()<<' '<<a.min()<<endl;
    return 0;
}