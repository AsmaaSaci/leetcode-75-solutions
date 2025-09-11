#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeros = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;

            // إذا الأصفار أكثر من المسموح
            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    cout << sol.longestOnes(nums1, 2) << endl; // 6

    vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << sol.longestOnes(nums2, 3) << endl; // 10
}
