#include<algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() != 5)
			return false;
		sort(numbers.begin(), numbers.end());
		int countZero = 0, countInterval = 0;
		int i = 0;
		for (; i < 5 && numbers[i] == 0; i++)
			countZero++;
		for (; i < 5; i++) {
			if (i > 0 && numbers[i] == numbers[i - 1])
				return false;
			if (i > 0 && numbers[i - 1]!=0 && numbers[i] != numbers[i - 1])
				countInterval += numbers[i] - numbers[i - 1] - 1;
		}
		if (countInterval > countZero)
			return false;
		else
			return true;
	}
};
int main() {
	vector<int> input = { 0,3,1,6,4 };
	cout<<Solution().IsContinuous(input);
}
