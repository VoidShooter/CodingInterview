#include <iostream>
using namespace std;
class Solution {
public:
    bool g_InvalidInput = false;
    double Power(double base, int exponent) {
        g_InvalidInput = false;
        if(equal(base, 0.0)&&exponent<0){
            g_InvalidInput = true;
            return 0.0;
        }
        int absExponent = exponent;
        if(exponent<0) absExponent = -exponent;
        double result = PowerWithUnsignedExponent(base,absExponent);
        if(exponent<0) result = 1.0 / result;
        return result;
    }
private:
    bool equal(double num1, double num2){
        if(num1-num2>-0.000001&&num1-num2<0.000001) return true;
        else return false;
    }
    double PowerWithUnsignedExponent(double base, int exponent){
        if(exponent==0) return 1.0;
        if(exponent==1) return base;
        double result = PowerWithUnsignedExponent(base,exponent>>1);
        result *= result;
        if(exponent&1) result *= base;
        return result;
    }
};
int main() {
    cout<<Solution().Power(2,10);
    return 0;
}