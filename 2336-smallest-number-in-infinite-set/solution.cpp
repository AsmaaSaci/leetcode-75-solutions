#include <iostream>
#include <set>
#include <queue>
using namespace std;

class SmallestInfiniteSet {
    int current;
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> inPQ;
public:
    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {
        if (!pq.empty()) {
            int val = pq.top();
            pq.pop();
            inPQ.erase(val);
            return val;
        }
        return current++;
    }

    void addBack(int num) {
        if (num < current && !inPQ.count(num)) {
            pq.push(num);
            inPQ.insert(num);
        }
    }
};

int main() {
    SmallestInfiniteSet s;
    s.addBack(2);
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    s.addBack(1);
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
}
