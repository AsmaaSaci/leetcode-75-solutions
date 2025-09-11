#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        
        // عد التكرارات
        for (int num : arr) {
            freq[num]++;
        }
        
        unordered_set<int> occurrences;
        for (auto &p : freq) {
            occurrences.insert(p.second);
        }
        
        return occurrences.size() == freq.size();
    }
};
