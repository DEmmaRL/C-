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
using pii = pair<lli, lli>;

void solve() {
    double x1,x2,y1,y2;

    cin>>x1>>y1>>x2>>y2;

    double res = sqrt(( abs(x1-x2) * abs(x1-x2) ) + ( abs(y1-y2) * abs(y1-y2) )) ;
    cout<<setprecision(17)<<res<<endl;
}

int main() {
    IO;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
