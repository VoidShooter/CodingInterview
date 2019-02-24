#include <iostream>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i=0;i<length-1;i++){
            for(int j=i+1;j<length;j++){
                if (numbers[i]==numbers[j])
                {
                    *duplication = numbers[i];
                    return true;
                };
            }
        }
        return false;
    }
};
int main() {
    int input[]={2,3,2,0,2,5,3};
    int len = sizeof(input) / sizeof(input[0]);
    int duplication;
    cout<<Solution().duplicate(input, len, &duplication)<<endl;
    cout<<duplication;
    return 0;
}