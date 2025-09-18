#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;
        for (int s : spells) {
            long long need = (success + s - 1) / s;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ans.push_back(m - (it - potions.begin()));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> spells1 = {5,1,3};
    vector<int> potions1 = {1,2,3,4,5};
    auto res1 = sol.successfulPairs(spells1, potions1, 7);
    for (int x : res1) cout << x << " "; // 4 0 3
    cout << endl;

    vector<int> spells2 = {3,1,2};
    vector<int> potions2 = {8,5,8};
    auto res2 = sol.successfulPairs(spells2, potions2, 16);
    for (int x : res2) cout << x << " "; // 2 0 2
    cout << endl;
}
