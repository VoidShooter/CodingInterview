#include <iostream>
using namespace std;
class Solution {
public:
    int movingCount(const int threshold, const int rows, const int cols){
        if(threshold<0&&rows<1&&cols<1)
            return 0;
        bool* visited = new bool[rows*cols];
        memset(visited,0,rows*cols);
        int count = movingCountCore(threshold, rows, cols, visited, 0, 0);
        delete[] visited;
        return count;
    }

private:
    int movingCountCore(const int threshold, const int rows, const int cols, bool* visited, int row, int col){
        int count = 0;
        if(row<rows&&col<cols&&row>=0&&col>=0&&!visited[row*cols+col]&&digitalSum(row)+digitalSum(col)<=threshold){
            visited[row*cols+col] = true;
            count = 1+movingCountCore(threshold, rows, cols, visited, row+1, col)
                    +movingCountCore(threshold, rows, cols, visited, row, col+1)
                    +movingCountCore(threshold, rows, cols, visited, row-1, col)
                    +movingCountCore(threshold, rows, cols, visited, row, col-1);
        }
        return count;
    }
    int digitalSum(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
int main() {

    cout<<Solution().movingCount(15, 20, 20);
    return 0;
}