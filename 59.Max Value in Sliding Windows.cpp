#include<vector>
#include<deque>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size){
		if (num.size() < 1 || size < 1 || num.size() < size)
			return {};
		vector<int>maxInWindows;
		deque<int> index;
		for (unsigned int i = 0; i < num.size(); i++) {
			while (!index.empty() && num[i] > num[index.back()])
				index.pop_back();
			while (!index.empty() && i - index.front() + 1 > size)
				index.pop_front();
			index.push_back(i);
			if (i >= size - 1)
				maxInWindows.push_back(num[index.front()]);
		}
		return maxInWindows;
	}
};

int main() {
	vector<int> array = { 2,3,4,2,6,2,5,1 };
	vector<int> ret = Solution().maxInWindows(array, 3);
}
