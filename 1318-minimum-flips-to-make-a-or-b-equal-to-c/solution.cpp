#include <iostream>
using namespace std;

int minFlips(int a, int b, int c) {
    int flips = 0;
    while (a > 0 || b > 0 || c > 0) {
        int abit = a & 1;
        int bbit = b & 1;
        int cbit = c & 1;

        if (cbit == 0) {
            flips += abit + bbit; // أي 1 يحتاج flip
        } else {
            if (abit == 0 && bbit == 0) flips++; // نحتاج واحد
        }

        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    return flips;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << minFlips(a, b, c) << endl;
    return 0;
}
