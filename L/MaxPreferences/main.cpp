#include <iostream>
#include <vector>
#include <set>

using namespace std;


int maxPreferences(const vector<int> &vec, int index, int total) {
//    Base case: max element in vector (choose only one element)
    int maxvalue = vec[0];
    for(int i = 0; i < vec.size(); i++) {
        maxvalue = max(maxvalue, vec[i]);
    }

    cout << "maxvalue = " << maxvalue << endl;
//    Max tai moi vi tri'=> moi vi tri + them vec[i] => compare value tai i va max truoc do
    int final = maxvalue;
    set<int> mySet;
    for(int i = 0; i < vec.size(); i++) {
        total += vec[i];
        if(final < total) {
            final = total;
        }
    }
//    mySet.insert(final);
//    return *mySet.end();
    return final;
}

int main()
{
//    vector<int> myVec {3,1,-2,5,-3};
    vector<int> myVec {-1,-1,-1,-1,-1};

    cout << maxPreferences(myVec, 0, 0) << endl;
    return 0;
}
