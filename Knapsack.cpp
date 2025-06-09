#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) cin >> wt[i] >> val[i];
    vector<int> dp(w + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = w; j >= wt[i]; j--)
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
    }
    cout << dp[w] << "\n";
    return 0;
}

Example Input:
4 7
1 1
3 4
4 5
5 7

Expected output:
9
