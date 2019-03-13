#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution {
public:
	static bool compare(string str1, string str2) {
		return (str1 + str2) < (str2 + str1);
	}
	string PrintMinNumber(vector<int> numbers) {
		string output;
		if (numbers.size() <1)
			return output;
		vector<string> vetStr;
		for (int i = 0; i < numbers.size(); i++) {
			stringstream ss;
			ss << numbers[i];
			vetStr.push_back(ss.str());
		}
		sort(vetStr.begin(), vetStr.end(), compare);
		for (int i = 0; i < vetStr.size(); i++) {
			output.append(vetStr[i]);
		}
		return output;
	}
};
int main() {
	cout << Solution().PrintMinNumber({ 321,12,231,23 });
}
