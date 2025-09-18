#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,1};
    cout << s.findPeakElement(nums1) << endl; // 2

    vector<int> nums2 = {1,2,1,3,5,6,4};
    cout << s.findPeakElement(nums2) << endl; // 1 or 5
}
