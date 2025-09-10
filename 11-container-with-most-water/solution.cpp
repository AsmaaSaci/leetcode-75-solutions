#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        int width = right - left;
        int area = min(height[left], height[right]) * width;
        max_area = max(max_area, area);

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max_area;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;  // Output: 49
    return 0;
}
