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
    int n, k;
    cin >> n >> k;
    if(k==1){
        fore(i,1,n+1){
            cout<<i<<" ";
        }
        cout<<endl;
        return ;
    }

    vi perm(n) , reservados ,extra;

    int p = n / k , r = n % k;
    fore(i, 1, p + 1) {
        reservados.pb(i);
    }

    for (int i = n; i > n - r; --i) {
        extra.pb(i);
    }

    int idx = 0;
    for (int x : extra) {
        perm[idx++] = x;
    }

    int reserved_idx = 0;
    for (int i = p + 1; idx < n; ++i) {
        if ( (idx+1) % k == 0 && reserved_idx < reservados.size()) {
            perm[idx++] = reservados[reserved_idx++];
        }
        if (idx < n) perm[idx++] = i;
    }
    for(int i = 0 ; i < n ; ++i ) {
        cout << perm[i] << " ";
    }
    cout << ENDL;
}

int main() {
    IO;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
