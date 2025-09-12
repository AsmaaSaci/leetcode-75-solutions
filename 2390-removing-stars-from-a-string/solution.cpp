#include <bits/stdc++.h>
using namespace std;

string removeStars(string s) {
    string result;
    for (char c : s) {
        if (c == '*') result.pop_back();
        else result.push_back(c);
    }
    return result;
}

int main() {
    string s = "leet**cod*e";
    cout << removeStars(s) << endl;
    return 0;
}
