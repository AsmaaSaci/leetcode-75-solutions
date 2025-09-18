#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = n - 1;
        long long ans = 0;
        
        using P = pair<int,int>; // {cost, index}
        priority_queue<P, vector<P>, greater<P>> pq;
        
        // اضافة من اليسار
        for (int i = 0; i < candidates && left <= right; i++) {
            pq.push({costs[left], left});
            left++;
        }
        // اضافة من اليمين
        for (int i = 0; i < candidates && left <= right; i++) {
            pq.push({costs[right], right});
            right--;
        }
        
        for (int hire = 0; hire < k; hire++) {
            auto [cost, idx] = pq.top(); 
            pq.pop();
            ans += cost;
            
            if (left <= right) {
                if (idx < left) { // أخذناه من الجهة اليسار
                    pq.push({costs[left], left});
                    left++;
                } else { // أخذناه من الجهة اليمين
                    pq.push({costs[right], right});
                    right--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> costs = {17,12,10,2,7,2,11,20,8};
    cout << s.totalCost(costs, 3, 4) << endl; // 11
}
