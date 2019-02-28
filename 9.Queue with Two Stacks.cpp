#include <iostream>
#include <stack>
#include <exception>
using namespace std;
class Solution
{
public:
    void push(int node) {
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        if(!stack2.empty()){
            int temp=stack2.top();
            stack2.pop();
            return temp;
        }
        return -1;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
int main() {
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    return 0;
}