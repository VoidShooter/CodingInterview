#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	string ReverseSentence(string str) {
		int len = str.size();
		if (len <= 1)
			return str;
		Reverse(str, 0, len - 1);
		int left = 0, right;
		while (left < len) {
			if (str[left] == ' ') {
				left++;
				continue;
			}
			right = left;
			while (str[right + 1] != ' '&&str[right + 1] != '\0')
				right++;
			Reverse(str, left, right);
			left = right + 1;
		}
		return str;
	}
private:
	void Reverse(string& str, int left, int right) {
		while (left < right) {
			char temp = str[left];
			str[left] = str[right];
			str[right] = temp;
			left++;
			right--;
		}
	}
};

int main() {
	string str = "   ";
	string ret = Solution().ReverseSentence(str);
	cout << str;
}
