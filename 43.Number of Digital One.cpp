#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n){
		int counter = 0;
		int i = 1;
		int current = 0, after = 0, before = 0;
		while ((n / i) != 0) {
			before = n / i / 10;
			current = (n / i) % 10; 
			after = n - (n / i) *i;
			if (current == 0)
				counter += before * i;
			else if (current == 1)
				counter += before * i + after + 1;
			else
				counter += (before + 1) * i;
			i = i * 10;
		}
		return counter;
	}
};
int main() {
	cout << Solution().NumberOf1Between1AndN_Solution(10000);
}
