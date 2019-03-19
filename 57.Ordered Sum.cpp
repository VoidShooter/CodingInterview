#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int len = array.size();
		if (len < 2)
			return {};
		vector<int> ret;
		int left = 0, right = len - 1;
		while (left < right) {
			if (array[left] + array[right] == sum) {
				ret.push_back(array[left]);
				ret.push_back(array[right]);
				break;
			}
			if (array[left] + array[right] > sum)
				right--;
			else
				left++;
		}
		return ret;
	}
};

int main() {
	vector<int> array = { 1,3,5,7,9,10 };
	vector<int> ret = Solution().FindNumbersWithSum(array, 12);
	cout << ret[0] << endl << ret[1];
}
