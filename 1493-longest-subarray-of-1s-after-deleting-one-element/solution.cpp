#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;

            // إذا عندنا أكثر من صفر، قلّص من اليسار
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            // ناقص 1 لأن لازم نحذف عنصر
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,1,0,1};
    cout << sol.longestSubarray(nums1) << endl; // 3

    vector<int> nums2 = {0,1,1,1,0,1,1,0,1};
    cout << sol.longestSubarray(nums2) << endl; // 5

    vector<int> nums3 = {1,1,1};
    cout << sol.longestSubarray(nums3) << endl; // 2

    return 0;
}
