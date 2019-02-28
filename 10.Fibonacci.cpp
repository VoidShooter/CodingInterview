#include <iostream>
using namespace std;
class Solution
{
public:
    int Fibonacci(int n) {
        if(n<=1) return n;
        int a=0, b=1, sum;
        for(int i=2;i<=n;i++){
            sum = a+b;
            a = b;
            b = sum;
        }
        return sum;
    }
};
int main() {
    //0 1 1 2 3 5 8
    cout<<Solution().Fibonacci(4);
    return 0;
}