#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k > len)
			return vector<int>();

		multiset<int, greater<int>> leastNums;
		
		for (auto itInput = input.begin(); itInput != input.end(); itInput++) {
			if (leastNums.size() < k) {
				leastNums.insert(*itInput);
			}
			else {
				if (*itInput < *leastNums.begin()) {
					leastNums.erase(leastNums.begin());
					leastNums.insert(*itInput);
				}
			}
		}
		return vector<int>(leastNums.begin(), leastNums.end());
	}
};
int main(){
	vector<int> numbers = { 5,1,2,3,9,4,6,7,5,2,2,2,2,2,2,2,5 };
	vector<int> output = Solution().GetLeastNumbers_Solution(numbers, 5);
}
