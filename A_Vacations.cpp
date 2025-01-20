#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for(lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    fore(i, 0, n) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(3, 1e9));
    dp[0][0] = 0;

    fore(i, 1, n + 1) {
        
        dp[i][0] = min({
            dp[i - 1][0], 
            dp[i - 1][1], 
            dp[i - 1][2]
            }) + 1;

        if (a[i - 1] == 1 || a[i - 1] == 3) {
            dp[i][1] = min(
                dp[i - 1][0], 
                dp[i - 1][2]
                );
        }
        if (a[i - 1] == 2 || a[i - 1] == 3) {
            dp[i][2] = min(
                dp[i - 1][0], 
                dp[i - 1][1]
                );
        }
    }
    cout << min({
        dp[n][0], 
        dp[n][1], 
        dp[n][2]
        }) << ENDL;
}

int main() {
    IO;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
