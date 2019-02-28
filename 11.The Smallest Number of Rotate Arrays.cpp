#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0) return 0;
        int left = 0, right = rotateArray.size() - 1, center;
        while(left + 1 != right){
            center = ((right - left)>>1) + left;
            if(rotateArray[center]>=rotateArray[left]) left = center;
            else if(rotateArray[center]<=rotateArray[right]) right = center;
        }
        return rotateArray[right];
    }
};
int main() {
    vector<int> array={3,4,5,1,2};
    cout<<Solution().minNumberInRotateArray(array);
    return 0;
}