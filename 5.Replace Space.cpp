#include <iostream>
using namespace std;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        int length_before = strlen(str), counter_space = 0;
        for(int i = 0;i<length_before;i++){
            if(str[i]==' ') counter_space++;
        }
        int length_after = length_before + 2 * counter_space;
        int p = length_after;
        for(int i = length_before;i >= 0;i--){
            if(str[i] == ' '){
                str[p--] = '0';
                str[p--] = '2';
                str[p--] = '%';
            } else{
                str[p--] = str[i];
            }
        }
    }
};
int main() {
    int length = 10;
    char *str = new char[length];
    strcpy(str,"ab cd");
    cout<<strlen(str)<<endl;
    Solution().replaceSpace(str, length);
    cout<<strlen(str)<<endl<<str<<endl;
    return 0;
}