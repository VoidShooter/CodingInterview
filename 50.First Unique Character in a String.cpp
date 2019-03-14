#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.size() < 1)
			return -1;
		int len = str.size(), result=-1;
		char *charHash = new char[256];
		memset(charHash, 0, 256);
		for (int i = 0; i < len; i++)
			charHash[str[i]]++;
		for(int i=0;i<len;i++){
			if (charHash[str[i]] == 1) {
				result = i;
				break;
			}
		}
		return result;
	}
};
int main() {
	cout << Solution().FirstNotRepeatingChar("abcadbefg");
}
