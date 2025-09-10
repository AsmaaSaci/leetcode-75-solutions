#include <vector>
#include <iostream>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int insertPos = 0;
    for (int num : nums) {
        if (num != 0) {
            nums[insertPos++] = num;
        }
    }
    while (insertPos < nums.size()) {
        nums[insertPos++] = 0;
    }
}

int main() {
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for (int n : nums) cout << n << " ";
    cout << endl;
    return 0;
}
