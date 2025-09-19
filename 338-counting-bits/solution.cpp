#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n+1, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> res = countBits(n);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
