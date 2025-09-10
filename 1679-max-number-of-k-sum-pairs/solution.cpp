#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int ops = 0;

    for (int num : nums) {
        int complement = k - num;
        if (freq[complement] > 0) {
            // We found a pair
            ops++;
            freq[complement]--;
        } else {
            freq[num]++;
        }
    }

    return ops;
}

int main() {
    vector<int> nums1 = {1,2,3,4};
    cout << maxOperations(nums1, 5) << endl;  // Output: 2

    vector<int> nums2 = {3,1,3,4,3};
    cout << maxOperations(nums2, 6) << endl;  // Output: 1

    return 0;
}
