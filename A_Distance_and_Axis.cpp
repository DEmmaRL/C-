#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(lli i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

int lca(const string &a, const string &b) {
    int n = sz(a), m = sz(b);
    vector<vector<int>> dp(2, vector<int>(m + 1, 0));
    
    fore(i, 1, n + 1) {
        fore(j, 1, m + 1) {
            if (a[i - 1] == b[j - 1]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            } else {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
    }
    
    return dp[n % 2][m];
}

int main() {
    IO;
    string a = "abcde", b = "ace";
    cout << "Length of LCS: " << longestCommonSubsequence(a, b) << ENDL;
    return 0;
}
