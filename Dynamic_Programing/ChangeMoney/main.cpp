#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

int waytoChange(const int &value, vector<int>& arr) {
    if (value == 0) return 1;
    if((value < 0) || arr.empty()) {
        return 0;
    }

    //ways(5) = way use x + way no use x
    map<pair<int, int>, int> mem;
    if(mem.find({value, arr.size()}) == mem.end()) {//value is not enough to be unique, arr?
        int finalElement = arr.back();
        vector<int> oriVector(arr.begin(), arr.end());
        arr.pop_back();

        mem[{value, arr.size()}] = waytoChange(value - finalElement, oriVector) + waytoChange(value, arr);
    }
    return mem[{value, arr.size()}];
}

int main()
{
    //doi so tien = 5 với các mệnh giá [5,2,1]


    vector<int> inputArr {1, 5, 2};
    cout << waytoChange(100, inputArr) << endl;
    return 0;
}
