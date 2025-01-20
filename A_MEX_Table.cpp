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
    lli n, m;
    cin>> n >> m;
    cout <<max( n, m ) + 1 << endl;
}

int main() {
    IO;
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
