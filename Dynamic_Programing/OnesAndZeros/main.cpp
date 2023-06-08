#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

//count 1 and 0 in each string
int countOnes(const string& inputStr) {
    int count = 0;
    for(auto ele : inputStr) {
        if(ele == '1') count++;
    }
    return count;
}

int countZeros(const string& inputStr) {
    int count = 0;
    for(auto ele : inputStr) {
        if(ele == '0') count++;
    }
    return count;
}

//recursion
int maxSubset(const vector<string> arr, const int &numberOfOnes, const int &numberOfZeros,
              const int& i, map<tuple<int, int, int>, int> &mem) {

    //stoping condition
    if(i == arr.size()) {
        return 0;
    }
    if((numberOfOnes < 0) || (numberOfZeros < 0)) return INT_MIN;

    if(mem.find({i, numberOfOnes, numberOfZeros}) == mem.end()) {
        //skip str
        int skip = maxSubset(arr, numberOfOnes, numberOfZeros, i + 1, mem);
        cout << "skip = " << skip << endl;
        //get str
        //calculate zero and one of each string
        int onesInThisStr = countOnes(arr[i]);
        int zerosInThisStr = countZeros(arr[i]);
        int take = maxSubset(arr, numberOfOnes - onesInThisStr, numberOfZeros - zerosInThisStr, i + 1, mem) + 1;
        cout << "take = " << take << endl;


        mem[{i, numberOfOnes, numberOfZeros}] = max(skip, take);
    }
    return mem[{i, numberOfOnes, numberOfZeros}];
}

int main()
{
    vector<string> arr{"10", "1", "0"};
    int numberOfOnes = 0;
    int numberOfZeros = 0;
    map<tuple<int, int, int>, int> mem;
    cout << maxSubset(arr, numberOfOnes, numberOfZeros, 0, mem) << endl;
    return 0;
}
