#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() < 1) return 0;
		int middle = numbers.size() >>1;
		int L = 0;
		int R = numbers.size() - 1;
		vector<int> index = partition(numbers, L, R);
		while (index[0] > middle || index[1] < middle) {
			if (index[0] > middle) {
				R = index[0] - 1;
				index = partition(numbers, L, R);
			}
			else {
				L = index[1] + 1;
				index = partition(numbers, L, R);
			}	
		}
		if(CheckInvalidArray(numbers, numbers[middle]))
			return numbers[middle];
		else return 0;
	}
	bool CheckInvalidArray(vector<int> &numbers, int number) {
		int times = 0;
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] == number)
				times++;
			else
				times--;
		}
		if (times > 0) return true;
		else return false;
	}
	vector<int> partition(vector<int>& arr, int l, int r) {
		int less = l - 1, more = r;
		while (l < more) {
			if (arr[l] < arr[r]) {
				swap(arr, ++less, l++);
			}
			else if (arr[l] > arr[r]) {
				swap(arr, --more, l);
			}
			else {
				l++;
			}
		}
		swap(arr, more, r);
		return { less + 1,more };
	}
	void swap(vector<int> &arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};
int main(){
	vector<int> numbers = { 5,1,2,3,9,4,6,7,5,2,2,2,2,2,2,2,5 };
	cout << Solution().MoreThanHalfNum_Solution(numbers);
}
