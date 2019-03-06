#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> array_temp;
        for(auto ib1 = array.begin();ib1 != array.end();){
            if(*ib1 % 2 == 0){
                array_temp.push_back(*ib1);
                ib1 = array.erase(ib1);
            }
            else{
                ib1++;
            }
        }
        for(auto ib2 = array_temp.begin();ib2!=array_temp.end();ib2++){
            array.push_back(*ib2);
        }
    }
//    void reOrderArray(vector<int> &array) {
//        int L = 0, R = array.size()-1;
//        while (L < R){
//            if(array[L]%2==1)
//                L++;
//            else{
//                array[L] = array[L] ^ array[R];
//                array[R] = array[L] ^ array[R];
//                array[L] = array[L] ^ array[R];
//                R--;
//            }
//        }
//    }
    void printArray(vector<int> &array){
        int len = array.size();
        for(int i = 0;i < len;i++){
            cout<<array[i]<<endl;
        }
    }
};
int main() {
    vector<int> arr={1,2,3,4,5};
    Solution().reOrderArray(arr);
    Solution().printArray(arr);
    return 0;
}