#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> res;
    string prefix = "";

    for (char c : searchWord) {
        prefix += c;
        vector<string> temp;
        auto it = lower_bound(products.begin(), products.end(), prefix);
        for (int i = 0; i < 3 && it + i != products.end(); i++) {
            if ((it + i)->substr(0, prefix.size()) == prefix)
                temp.push_back(*(it + i));
        }
        res.push_back(temp);
    }

    return res;
}

int main() {
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";

    vector<vector<string>> res = suggestedProducts(products, searchWord);

    for (auto &v : res) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i != v.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
