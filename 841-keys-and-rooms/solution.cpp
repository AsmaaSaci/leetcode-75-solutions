#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        stack<int> st;
        
        st.push(0);
        visited[0] = true;
        int count = 1; // عدد الغرف اللي زرناها
        
        while (!st.empty()) {
            int room = st.top();
            st.pop();
            
            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    count++;
                    st.push(key);
                }
            }
        }
        
        return count == n;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    cout << (sol.canVisitAllRooms(rooms1) ? "true" : "false") << endl;

    vector<vector<int>> rooms2 = {{1,3}, {3,0,1}, {2}, {0}};
    cout << (sol.canVisitAllRooms(rooms2) ? "true" : "false") << endl;

    return 0;
}
