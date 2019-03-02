#include <iostream>
using namespace std;
class Solution {
public:
    int  NumberOf1(int n) {
        int count=0;
        while(n){
            count++;
            n = n & (n-1);
        }
        return count;
    }
};
int main() {
    cout<<Solution().NumberOf1(-1);
    return 0;
}