class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = *max_element(candies.begin(), candies.end());
    vector<bool> result;

    for (int candy : candies) {
        if (candy + extraCandies >= maxCandies)
            result.push_back(true);
        else
            result.push_back(false);
    }
    return result;
}

int main() {
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    vector<bool> result = kidsWithCandies(candies, extraCandies);

    for (bool r : result) {
        cout << (r ? "true " : "false ");
    }
    cout << endl;

    return 0;
}
};