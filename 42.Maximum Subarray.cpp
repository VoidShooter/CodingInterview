#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int len = array.size();
		if (len < 1)
			return 0;
		int thismax = array[0];
		int totalmax = thismax;
		for (int i = 1; i <= len - 1; i++) {
			thismax = array[i] > (thismax + array[i]) ? array[i] : (thismax + array[i]);
			totalmax = totalmax > thismax ? totalmax : thismax;
		}
		return totalmax;
	}
};
int main() {
	vector<int> array = { 6, -3, -2, 7, -15, 1, 2, 2 };
	cout << Solution().FindGreatestSumOfSubArray(array);
}
