#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;

void solve() {
    lli n, k;
    cin >> n >> k;
    vi a(n), b(n);
    fore(i,0 ,n) 
        cin>> a[i];
    fore(i,0 ,n) 
        cin>> b[i];
    vector<pair<lli, lli>> c(n);
    for (lli i = 0; i < n; i++) {
        c[i] = {b[i], a[i]};
    }
    sort(all(c));
    lli l = 1, r = c.back().first, maxi = 0;
    while (l <= r) {
        lli mid = (l + r) / 2;

        lli p = 0, nega = 0, rest = 0;
        for (auto e : c) {
            
            if (mid <= e.ss) {
                p++;
                rest += mid;
            
            } else if (mid <= e.ff) {
                nega++;
                rest += mid;
            }
        }

        if (nega <= k) {
            maxi = max(maxi, rest);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << maxi << ENDL;
}

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
