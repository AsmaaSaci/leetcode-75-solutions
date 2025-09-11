#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        long long maxSum = windowSum;

        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,12,-5,-6,50,3};
    int k1 = 4;
    cout << sol.findMaxAverage(nums1, k1) << endl; 

    vector<int> nums2 = {5};
    int k2 = 1;
    cout << sol.findMaxAverage(nums2, k2) << endl; 
}
