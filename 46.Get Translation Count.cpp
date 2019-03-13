#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int GetTranslationCount(int number) {
		if (number < 0)
			return 0;
		string numberStr = to_string(number);
		return GetTranslationCount(numberStr);
	}
private:
	int GetTranslationCount(string number) {
		int len = number.length();
		int* result = new int[len];
		result[len-1] = 1;
		for (int i = len-2; i >=0; i--) {
			if (i<=len-3 && (number[i] == '1' || number[i] == '2') && number[i + 1] <= '5')
				result[i] = result[i + 1] + result[i + 2];
			else
				result[i] = result[i + 1];
		}
		return result[0];
	}
};
int main() {
	cout << Solution().GetTranslationCount(12258);
}
