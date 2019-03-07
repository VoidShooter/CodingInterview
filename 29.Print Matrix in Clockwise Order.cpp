#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> output;
        output.clear();
        if(matrix.size()<=0||matrix[0].size()<=0)
            return output;
        int columns = (int)matrix.size();
        int rows = (int)matrix[0].size();
        int circle = ((columns<rows?columns:rows)-1)/2+1;
        for(int start = 0;start<circle;start++){
            int endX = rows - 1 - start;
            int endY = columns - 1 - start;
            for(int i=start;i<=endX;i++)
                output.push_back(matrix[start][i]);
            if(start<endY){
                for(int i=start+1;i<=endY;i++)
                    output.push_back(matrix[i][endX]);
            }
            if(start<endX&&start<endY){
                for(int i=endX-1;i>=start;i--)
                    output.push_back(matrix[endY][i]);
            }
            if(start<endY-1&&start<endX){
                for(int i=endY-1;i>=start+1;i--)
                    output.push_back(matrix[i][start]);
            }
        }
        return output;
    }
};
int main() {
//    vector<vector<int>> matrix={{1, 2, 3, 4},
//                                {5, 6, 7, 8},
//                                {9, 10,11,12},
//                                {13,14,15,16}};
    vector<vector<int>> matrix={{1, 2},
                                {5, 6},
                                {9, 10},
                                {13,14}};
    vector<int> output = Solution().printMatrix(matrix);
    for(auto it = output.begin();it!=output.end();it++)
        cout<<*it<<endl;
    return 0;
}
