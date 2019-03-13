#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int digitAtIndex(int index){
		int length = 1; //length of index 
		int lessIndex = 1; //minimum index in the length
		int moreIndex = 10; //maximum index in the length
		while (index > moreIndex) {
			length ++;
			lessIndex = moreIndex + 1;
			moreIndex = moreIndex + (int)pow(10,length-1)*9*length;
		}
		int indexBias = index - lessIndex + 1;
		int bitBias = indexBias % length;
		int number;
		if (length == 1)
			number = index - 1;
		else
			number = (int)pow(10, length - 1) - 1 + indexBias / length;
		if (bitBias)
			number++;
		while (bitBias) {
			number /= 10;
			bitBias--;
		}
		return number % 10;
	}
};
int main() {
	cout << Solution().digitAtIndex(1) << endl;
	cout << Solution().digitAtIndex(3) << endl;
	cout << Solution().digitAtIndex(9) << endl;
	cout << Solution().digitAtIndex(10) << endl;
	cout << Solution().digitAtIndex(11) << endl;
	cout << Solution().digitAtIndex(12) << endl;
}
