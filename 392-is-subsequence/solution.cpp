bool isSubsequence(string s, string t) {
    int i = 0;  // pointer for s
    for (char c : t) {
        if (i < s.size() && s[i] == c) {
            i++;
        }
    }
    return i == s.size();
}

int main() {
    cout << boolalpha;
    cout << isSubsequence("abc", "ahbgdc") << endl;  // true
    cout << isSubsequence("axc", "ahbgdc") << endl;  // false
    return 0;
}