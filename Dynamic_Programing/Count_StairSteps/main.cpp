#include <iostream>
#include <unordered_map>

using namespace std;

int climbStairs(const int &n, unordered_map<int, int> &mem) {
    cout << "Going n = " << n << endl;
    //mem(stt bac thang, cach)
    if ((n == 0) || (n == 1)) {
        return 1;
    }
    //check store ways of bac thang n yet?
    if(mem.find(n) == mem.end()) {
        mem[n] = climbStairs(n - 1, mem) + climbStairs(n - 2, mem);
    }

    cout << n << " => " << mem[n] << endl;
    return mem[n];
}

int main()
{
    //ways(n) = ways(n - 1) + ways(n - 2); can go 1 or 2 steps
    unordered_map<int, int> mem;
    cout << climbStairs(10, mem) << endl;
    return 0;
}
