#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    void Insert(int num){
        if(setMax.size()>setMin.size())
            setMin.insert(num);
        else
            setMax.insert(num);
        while(!setMax.empty()&&!setMin.empty()&&*setMax.begin()>*setMin.begin()){
            int tempMax, tempMin;
            tempMax = *setMax.begin();
            tempMin = *setMin.begin();
            setMax.erase(setMax.begin());
            setMin.erase(setMin.begin());
            setMax.insert(tempMin);
            setMin.insert(tempMax);
        }
    }

    double GetMedian(){
        if(setMin.size()==setMax.size())
            return ((double)*setMax.begin() + (double)*setMin.begin())/2;
        else
            return *setMax.begin();
    }

private:
    multiset<int, greater<int>> setMax;
    multiset<int, less<int>> setMin;

};
int main() {
    Solution s;
    s.Insert(1);
    cout<<s.GetMedian()<<endl;
    s.Insert(8);
    cout<<s.GetMedian()<<endl;
    s.Insert(5);
    cout<<s.GetMedian()<<endl;
    s.Insert(9);
    cout<<s.GetMedian()<<endl;
    s.Insert(-1);
    cout<<s.GetMedian();
}