#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int rob(const vector<int> &arr, const int &index, unordered_map<int, int> &mem) {
    cout << "index = " << index << endl;
    //2 options in current house => trộm nhà trước đó || trộm nhà hiện tại và nhà trước đó nữa
    if(index > (arr.size() - 1)) return 0;
    if(mem.find(arr[index]) == mem.end()) {
        //trộm nhà hiện tại + trộm nhà mốt || bỏ nhà hiện tại trộm nhà tiếp theo
        mem[arr[index]] = max(rob(arr, index + 1, mem), rob(arr, index + 2, mem) + arr[index]);
    } else cout << "tinh roi" << endl;
    return mem[arr[index]];
}


int main()
{
    vector<int> arr{1, 2, 3, 1};
    unordered_map<int, int> mem;
    int lastIndex = arr.size() - 1;
    cout << rob(arr, 0, mem) << endl;
    return 0;
}
