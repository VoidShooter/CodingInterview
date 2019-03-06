#include <iostream>
using namespace std;
class Solution {
public:
    bool isNumeric(char* str){
        if(str == nullptr || strlen(str)<1) return false;
        int point = 0;

        bool flag = scanInteger(str);
        if(index<strlen(str)&&str[index]=='.'){
            index++;
            flag = scanUnsignedInteger(str) || flag;
        }
        if(index<strlen(str)&&(str[index]=='e'||str[index]=='E')){
            index++;
            flag = flag && scanInteger(str);
        }
        return flag && index==strlen(str);
    }
private:
    int index = 0;
    bool scanInteger(char* str){
        if(index<strlen(str)&&(str[index]=='+'||str[index]=='-'))
            index++;
        return scanUnsignedInteger(str);
    }
    bool scanUnsignedInteger(char* str){
        int start=index;
        while(index<strlen(str)&&str[index]>='0'&&str[index]<='9')
            index++;
        return start<index;
    }
};
int main() {
    char str[] = "123.45e+6";
    cout<<Solution().isNumeric(str);
    return 0;
}