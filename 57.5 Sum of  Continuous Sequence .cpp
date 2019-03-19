#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum < 3)
			return {};
		vector<vector<int> > ret;
		int left = 1, right = 2;
		while (left < right&&left<=sum/2) {
			int cur = (right + left) * (right - left + 1) / 2;
			if (cur < sum)
				right++;
			else if (cur > sum)
				left++;
			else if (cur == sum) {
				vector<int> temp;
				for (int i = left; i <= right; i++) {
					temp.push_back(i);
				}
				ret.push_back(temp);
				left++;
			}
		}
		return ret;
	}
};

int main() {
	vector<vector<int>> ret = Solution().FindContinuousSequence(12);
}
