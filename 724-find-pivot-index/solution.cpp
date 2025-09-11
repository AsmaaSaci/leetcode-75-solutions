#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int n : nums) totalSum += n;

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,7,3,6,5,6};
    cout << sol.pivotIndex(nums1) << endl; // 3

    vector<int> nums2 = {1,2,3};
    cout << sol.pivotIndex(nums2) << endl; // -1

    vector<int> nums3 = {2,1,-1};
    cout << sol.pivotIndex(nums3) << endl; // 0

    return 0;
}
