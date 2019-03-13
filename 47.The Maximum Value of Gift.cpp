#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int getMaxValue(const vector<vector<int>> map) {
		vector<vector<int>> value = map;
		int row = map.size();
		int col = map[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int left = 0;
				int up = 0;
				if (i > 0)
					up = value[i - 1][j];
				if (j > 0)
					left = value[i][j - 1];
				value[i][j] = max(left, up) + value[i][j];
			}
		}
		return value[row - 1][col - 1];
	}
};
int main() {
	vector<vector<int>> map = { {1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5} };
	cout << Solution().getMaxValue(map);
}
