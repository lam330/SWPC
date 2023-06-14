#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool targetSum(vector<int> vec, int target) {
    unordered_map<int, bool> myMap;
    myMap[0] = true;

    for(int i = 0; i < vec.size(); i++) {
        for(int j = target; j >= vec[i]; j--) {
            if(myMap[j - vec[i]] == true) {
                myMap[j] = true;//j => với tổng = j thì các giá trị trước đó trong vector có thể + lại = j
            }
        }
    }
    return myMap[target];
}

int main()
{
    vector<int> myVec {1 ,2 ,3 ,4, 5, -3};
    int target = 100;
    cout << targetSum(myVec, target) << endl;
    return 0;
}
