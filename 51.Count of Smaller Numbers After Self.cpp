#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	long long InversePairs(vector<int> data) {
		if (data.size() < 1)
			return 0;
		return mergeSort(data, 0, data.size() - 1);
	}
	long long  mergeSort(vector<int> &arr, int l, int r) {
		long long  result = 0;
		if (l == r) {
			return result;
		}
		int mid = l + ((r - l) >> 1);
		result += mergeSort(arr, l, mid);
		result += mergeSort(arr, mid + 1, r);
		result += merge(arr, l, r);
		return result;
	}
	long long   merge(vector<int>& arr, int l, int r) {
		vector<int> help;
		long long  result=0;
		int mid = l + ((r - l) >> 1);
		int p1 = l, p2 = mid + 1;
		int i = 0;
		while (p1 <= mid && p2 <= r) {
			if (arr[p1] > arr[p2]) {
				result += mid - p1 + 1;
				help.push_back(arr[p2++]);
			}
			else
				help.push_back(arr[p1++]);
		}
		while (p1 <= mid) {
			help.push_back(arr[p1++]);
		}
		while (p2 <= r) {
			help.push_back(arr[p2++]);
		}
		for (i = 0; i < help.size(); i++) {
			arr[l + i] = help[i];
		}
		return result;
	}
};
int main() {
	cout << Solution().InversePairs({2,3,5,6,1});
}
