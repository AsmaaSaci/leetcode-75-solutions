#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int g = gcd((int)str1.size(), (int)str2.size());
        return str1.substr(0, g);
    }
};

int main() {
    Solution sol;
    string str1 = "ABCABC", str2 = "ABC";
    cout << sol.gcdOfStrings(str1, str2) << endl; 
    return 0;
}
