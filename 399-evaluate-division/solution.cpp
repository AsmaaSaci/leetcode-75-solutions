#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dfs(string src, string dst, unordered_map<string, vector<pair<string,double>>>& graph, unordered_set<string>& visited) {
        if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) 
            return -1.0;
        if (src == dst) return 1.0;

        visited.insert(src);
        for (auto& [neighbor, weight] : graph[src]) {
            if (!visited.count(neighbor)) {
                double res = dfs(neighbor, dst, graph, visited);
                if (res != -1.0) return res * weight;
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }

        vector<double> results;
        for (auto& q : queries) {
            unordered_set<string> visited;
            double ans = dfs(q[0], q[1], graph, visited);
            results.push_back(ans);
        }
        return results;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> eq1 = {{"a","b"},{"b","c"}};
    vector<double> val1 = {2.0, 3.0};
    vector<vector<string>> q1 = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    auto r1 = sol.calcEquation(eq1, val1, q1);
    for (double x : r1) cout << x << " ";
    cout << endl;  // 6 0.5 -1 1 -1

    vector<vector<string>> eq2 = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> val2 = {1.5, 2.5, 5.0};
    vector<vector<string>> q2 = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    auto r2 = sol.calcEquation(eq2, val2, q2);
    for (double x : r2) cout << x << " ";
    cout << endl;  // 3.75 0.4 5 0.2

    vector<vector<string>> eq3 = {{"a","b"}};
    vector<double> val3 = {0.5};
    vector<vector<string>> q3 = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
    auto r3 = sol.calcEquation(eq3, val3, q3);
    for (double x : r3) cout << x << " ";
    cout << endl;  // 0.5 2 -1 -1
}
