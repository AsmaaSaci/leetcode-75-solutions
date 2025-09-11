#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0, maxAltitude = 0;
        for (int g : gain) {
            altitude += g;
            maxAltitude = max(maxAltitude, altitude);
        }
        return maxAltitude;
    }
};

int main() {
    Solution sol;
    vector<int> gain1 = {-5,1,5,0,-7};
    cout << sol.largestAltitude(gain1) << endl; // 1

    vector<int> gain2 = {-4,-3,-2,-1,4,3,2};
    cout << sol.largestAltitude(gain2) << endl; // 0

    return 0;
}
