#include <iostream>
using namespace std;
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str == nullptr || pattern == nullptr) return false;
        return matchCore(str, pattern);
    }
    bool matchCore(char* str, char* pattern){
        if(*str == '\0' && *pattern == '\0') return true;
        if(*str != '\0' && *pattern == '\0') return false;

        if(*(pattern+1) =='*'){
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
                return matchCore(str+1, pattern+2)  // * -> 1
                       || matchCore(str+1, pattern)  // * -> 2.3.4...
                       || matchCore(str, pattern+2);  // * -> 0
            else
                return matchCore(str, pattern+2); //* -> 0
        }
        if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
            return matchCore(str+1, pattern+1);
        return false;
    }
};
int main() {
    char str1[] = "aaa", str2[] = "ab*a";
    cout<<Solution().match(str1, str2);
    return 0;
}