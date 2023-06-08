#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

//int waysToMeetTarget(const vector<int> &arr, const int &target, const int &index) {
//    cout << index << endl;
//    if(index == (arr.size())) return (target == 0);
//    unordered_map<int, int> mem;
//    if(mem.find(target) == mem.end()) {
//        mem[target] = waysToMeetTarget(arr, target - 1, index + 1) + waysToMeetTarget(arr, target + 1, index + 1);
//    }
//    return mem[target];
//}

int waysToMeetTarget(const vector<int> &arr, const int &target, const int &index, const int &total, map<pair<int, int>, int> &mem) {
    if(index == arr.size()) return (total == target);
//    map<pair<int, int>, int> mem;
    cout << index << " " << total << endl;
    if(mem.find({index, total}) == mem.end()) {
        mem[{index, total}] = waysToMeetTarget(arr, target, index + 1, total + 1, mem) + waysToMeetTarget(arr, target, index + 1, total - 1, mem);
    } else cout << "else ne`" << endl;
    return mem[{index, total}];
}

int main()
{
    vector<int> inputArr {1, 1, 1, 1, 1};
    map<pair<int, int>, int> mem;
    cout << waysToMeetTarget(inputArr, 5, 0, 0, mem) << endl;
    return 0;
}
