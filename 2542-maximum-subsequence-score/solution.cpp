#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums2[i], nums1[i]};
        }
        sort(pairs.rbegin(), pairs.rend());

        long long sum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &p : pairs) {
            pq.push(p.second);
            sum += p.second;
            if ((int)pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if ((int)pq.size() == k) {
                ans = max(ans, sum * (long long)p.first);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,3,3,2};
    vector<int> nums2 = {2,1,3,4};
    cout << s.maxScore(nums1, nums2, 3) << endl; // 12

    vector<int> nums3 = {4,2,3,1,1};
    vector<int> nums4 = {7,5,10,9,6};
    cout << s.maxScore(nums3, nums4, 1) << endl; // 30
}
