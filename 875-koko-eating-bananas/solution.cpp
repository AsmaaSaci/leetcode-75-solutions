#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int p : piles) {
            hours += (p + k - 1) / k;
            if (hours > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> piles1 = {3,6,7,11};
    cout << s.minEatingSpeed(piles1, 8) << endl; // 4

    vector<int> piles2 = {30,11,23,4,20};
    cout << s.minEatingSpeed(piles2, 5) << endl; // 30

    vector<int> piles3 = {30,11,23,4,20};
    cout << s.minEatingSpeed(piles3, 6) << endl; // 23
}
