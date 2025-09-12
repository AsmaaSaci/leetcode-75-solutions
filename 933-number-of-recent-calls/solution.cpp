#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {}
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) q.pop();
        return q.size();
    }
};

int main() {
    RecentCounter recentCounter;
    cout << recentCounter.ping(1) << endl;
    cout << recentCounter.ping(100) << endl;
    cout << recentCounter.ping(3001) << endl;
    cout << recentCounter.ping(3002) << endl;
    return 0;
}
