#include <iostream>
#include <algorithm> 
using namespace std;

int gold[105][105];
int dp[105][105];

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> gold[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int best_prev = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            dp[i][j] = gold[i][j] + best_prev;
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}