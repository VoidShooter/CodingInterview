#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int temp = 0;
		for (int i = 0; i < data.size(); i++) {
			temp = temp ^ data[i];
		}
		int bit_index = 1;
		while (!(temp&bit_index)) {
			bit_index = bit_index << 1;
		}
		vector<int> result1, result2;
		for (int i = 0; i < data.size(); i++) {
			if (data[i] & bit_index)
				result1.push_back(data[i]);
			else
				result2.push_back(data[i]);
		}
		*num1 = 0;
		*num2 = 0;
		for (int i = 0; i < result1.size(); i++) {
			*num1 = *num1 ^result1[i];
		}
		for (int i = 0; i < result2.size(); i++) {
			*num2 = *num2 ^result2[i];
		}
	}
};

int main() {
	int num1, num2;
	vector<int> array = { 1,2,3,4,5,6,1,3,4,6 };
	Solution().FindNumsAppearOnce(array, &num1, &num2);
	cout << num1 << endl << num2;
}
