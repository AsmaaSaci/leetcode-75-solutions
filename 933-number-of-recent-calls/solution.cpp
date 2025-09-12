class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string result;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(num);
                resultStack.push(result);
                num = 0;
                result = "";
            } else if (c == ']') {
                int k = counts.top(); counts.pop();
                string prev = resultStack.top(); resultStack.pop();
                string temp;
                for (int i = 0; i < k; i++) temp += result;
                result = prev + temp;
            } else {
                result += c;
            }
        }
        return result;
    }
};
