class Solution {
public:
   string reverseVowels(string s) {
    unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && vowels.find(s[left]) == vowels.end()) left++;
        while (left < right && vowels.find(s[right]) == vowels.end()) right--;
        if (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

int main() {
    string s1 = "hello";
    string s2 = "leetcode";
    cout << reverseVowels(s1) << endl;  // holle
    cout << reverseVowels(s2) << endl;  // leotcede
    return 0;
}
};