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
            if(rotateArray[left]==rotateArray[right]&&rotateArray[left]==rotateArray[center]) return MinInOrder(rotateArray, left, right);
            else if(rotateArray[center]>=rotateArray[left]) left = center;
            else if(rotateArray[center]<=rotateArray[right]) right = center;
        }
        return rotateArray[right];
    }

private:
    int MinInOrder(vector<int> rotateArray, int left, int right){
        int result=rotateArray[left];
        for(int i=left+1;i<=right;i++){
            if (rotateArray[i]<result) result = rotateArray[i];
        }
        return result;
    }
};
int main() {
    vector<int> array={1,0,1,1,1};
    cout<<Solution().minNumberInRotateArray(array);
    return 0;
}
