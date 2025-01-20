#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
lli mod_exp(lli base, lli exp, lli mod) {
    lli result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
lli mod_inv(lli x, lli mod) {
    return mod_exp(x, mod - 2, mod);
}
lli nCr_mod(lli n, lli r, lli mod) {
    if (r > n) return 0;
    lli num = 1, denom = 1;
    for (lli i = 0; i < r; ++i) {
        num = (num * (n - i)) % mod;
        denom = (denom * (i + 1)) % mod;
    }
    return (num * mod_inv(denom, mod)) % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;

    cout << nCr_mod(n + m - 1, m - 1, MOD) << ENDL;
}

int main() {
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}
