#include <iostream>
using namespace std;
class Solution {
public:
    void Print1ToMaxOfNDigits(int n){
        if(n<=0) return;
        char* number = new char[n+1];
        number[n]='\0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
        delete[] number;
    }
    void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index){
        if(index == length){
            PrintNumber(number);
            return;
        }
        for(int i = 0;i<10;i++){
            number[index] = i + '0';
            Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
        }
    }
    void PrintNumber(char* number){
        int begin=0;
        while(number[begin] != ('/0') && number[begin]=='0'){
            begin++;
        }
        cout<<number+begin<<endl;
    }
};
int main() {
    Solution().Print1ToMaxOfNDigits(3);
    return 0;
}