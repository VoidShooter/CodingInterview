#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> output;
        int len = str.size();
        if(len<1) return output;
        if(len==1){
            output.push_back(str);
            return output;
        }
        string strTemp = str;
        for(int i=0;i<len;i++){
            if(i!=0 && strTemp[0]==strTemp[i]) continue;
            swap(strTemp[0], strTemp[i]);
            string resStr = strTemp.substr(1,len-1);
            vector<string> res = Permutation(resStr);
            for(int j=0;j<res.size();j++){
                output.push_back(strTemp[0]+res[j]);
            }
        }
        return output;
    }
};
int main() {
    string str = "aab";
    string test = "";
    vector<string> output = Solution().Permutation(str);
}