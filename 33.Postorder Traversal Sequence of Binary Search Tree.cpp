#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len==0) return false;
        if(len<3) return true;
        return VerifySquenceOfBST(sequence, 0, len-1);
    }

private:
    bool VerifySquenceOfBST(vector<int> sequence, int start, int end){
        if(end-start<2) return true;
        int mid, point=start;
        while(point<end&&sequence[point]<sequence[end]){
            point++;
        }
        mid = point;
        while(point<end){
            if(sequence[point]<sequence[end]) return false;
            point++;
        }
        return VerifySquenceOfBST(sequence, start, mid-1)
               && VerifySquenceOfBST(sequence, mid, end-1);
    }
};
int main() {
    vector<int> sequence={5,7,6,9,11,10,8};
    cout<<Solution().VerifySquenceOfBST(sequence);
    return 0;
}