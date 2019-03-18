#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() < 1)
			return 0;
		int left = GetLeftOfK(data, k, 0, data.size()-1);
		int right = GetRightOfK(data, k, 0, data.size() - 1);
		if (left != -1 && right != -1)
			return right - left + 1;
		else
			return 0;
	}
private:
	int GetLeftOfK(vector<int> data, int k, int left, int right) {
		if (right == left) {
			if (data[left] == k)
				return left;
			else
				return -1;
		}
		int mid = ((right - left) >> 1) + left;
		if (data[mid] < k)
			return GetLeftOfK(data, k, mid+1, right);
		else
			return GetLeftOfK(data, k, left, mid);
	}
	int GetRightOfK(vector<int> data, int k, int left, int right) {
		if (right == left) {
			if (data[left] == k)
				return left;
			else
				return -1;
		}
		int mid = ((right - left + 1) >> 1) + left;
		if (data[mid] > k)
			return GetRightOfK(data, k, left, mid-1);
		else
			return GetRightOfK(data, k, mid, right);
	}
};
int main() {
	vector<int> data = { 3,3,3,3,3,3,3 };
	cout << Solution().GetNumberOfK(data, 3);
}
