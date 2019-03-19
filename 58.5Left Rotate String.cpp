#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	string LeftRotateString(string str, int n) {
		int len = str.size();
		if (len <= 1||n<1||n>len-1)
			return str;
		Reverse(str, 0, len - 1);
		Reverse(str, 0, len - n - 1);
		Reverse(str, len - 1 - n + 1, len - 1);
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
	string str = "abcdef";
	string ret = Solution().LeftRotateString(str, 2);
	cout << str;
}
