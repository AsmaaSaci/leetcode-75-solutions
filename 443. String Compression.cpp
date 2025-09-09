#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int write = 0; 
    int read = 0;  
    
    while (read < n) {
        char currentChar = chars[read];
        int count = 0;

       
        while (read < n && chars[read] == currentChar) {
            read++;
            count++;
        }

       
        chars[write++] = currentChar;

       
        if (count > 1) {
            string cnt = to_string(count);
            for (char c : cnt) {
                chars[write++] = c;
            }
        }
    }

    return write;
}

int main() {
    vector<char> chars1 = {'a','a','b','b','c','c','c'};
    vector<char> chars2 = {'a'};
    vector<char> chars3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};

    cout << compress(chars1) << endl; // 6
    for (int i = 0; i < 6; i++) cout << chars1[i] << " ";
    cout << endl;

    cout << compress(chars2) << endl; // 1
    for (int i = 0; i < 1; i++) cout << chars2[i] << " ";
    cout << endl;

    cout << compress(chars3) << endl; // 4
    for (int i = 0; i < 4; i++) cout << chars3[i] << " ";
    cout << endl;

    return 0;
}
