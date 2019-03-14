#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int longestSubstringWithoutDuplication(string str) {
		int len = str.size();
		vector<int> position(256, -1);
		int result = 1, start = -1;
		for (int i = 0; i < len; i++) {
			start = max(start, position[str[i]]);
			result = max(result, i - start);
			position[str[i]] = i;
		}
		return result;
	}
};
int main() {
	string str ="abcdaefgb";
	cout << Solution().longestSubstringWithoutDuplication(str);
}
