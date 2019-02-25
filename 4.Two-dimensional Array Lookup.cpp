#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int column = array[0].size();
        int row_search = 0;
        for(int column_search = column - 1;column_search >= 0; column_search--){
            while(array[row_search][column_search] < target && row_search < row - 1) row_search ++;
            if(array[row_search][column_search] == target) return true;
        }
        return false;
    }
};
int main() {
    vector<vector<int> > array={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    int target=7;
    cout<<Solution().Find(target, array)<<endl;
    return 0;
}