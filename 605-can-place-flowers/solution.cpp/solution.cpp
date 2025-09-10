class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    for (int i = 0; i < size && n > 0; i++) {
        if (flowerbed[i] == 0) {
            bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
            bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);
            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                n--;
            }
        }
    }
    return n <= 0;
}

int main() {
    vector<int> flowerbed1 = {1,0,0,0,1};
    int n1 = 1;
    cout << (canPlaceFlowers(flowerbed1, n1) ? "true" : "false") << endl;

    vector<int> flowerbed2 = {1,0,0,0,1};
    int n2 = 2;
    cout << (canPlaceFlowers(flowerbed2, n2) ? "true" : "false") << endl;

    return 0;
}
};