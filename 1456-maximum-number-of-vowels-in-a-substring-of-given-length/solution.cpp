#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int count = 0;

        // أول نافذة
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) count++;
        }
        int maxCount = count;

        // حرك النافذة
        for (int i = k; i < s.size(); i++) {
            if (vowels.count(s[i])) count++;        // الحرف الجديد
            if (vowels.count(s[i - k])) count--;    // الحرف اللي خرج
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

int main() {
    Solution sol;
    cout << sol.maxVowels("abciiidef", 3) << endl; // 3
    cout << sol.maxVowels("aeiou", 2) << endl;    // 2
    cout << sol.maxVowels("leetcode", 3) << endl; // 2
    return 0;
}
