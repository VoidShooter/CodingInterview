#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		vector<int> result = { 1 };
		int p2 = 0, p3 = 0, p5 = 0;
		while (result.size() < index) {
			int temp = min(result[p2] * 2, result[p3] * 3);
			temp = min(temp, result[p5] * 5);
			result.push_back(temp);
			while (result[p2] * 2 <= result.back())
				p2++;
			while (result[p3] * 3 <= result.back())
				p3++;
			while (result[p5] * 5 <= result.back())
				p5++;
		}
		return result[index - 1];
	}
};
int main() {
	cout << Solution().GetUglyNumber_Solution(10);
}
