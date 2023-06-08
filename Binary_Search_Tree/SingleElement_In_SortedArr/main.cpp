#include <iostream>
#include <vector>

using namespace std;

int getSingleEle(const vector<int> &arr) {
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;

    while(low < high) {
        mid = (low + high) / 2;
        if(arr[mid * 2] == arr[mid * 2 +1]) low = mid + 1;
        else high = mid;
    }
    return arr[low * 2];//Get the first in final couple
}

int main()
{
    vector<int> vec{1,1,2,3,3,4,4};//always size la` so' le~
    cout << getSingleEle(vec) << endl;
    return 0;
}
