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
    int n ;
    cin>>n ;
    vi a(n), b(n);

    int res = 0 ;

    fore(i,0,n){
        cin>>a[i];
    }
    fore(i,0,n){
        cin>>b[i];
    }

    fore(i,0,n-1){
        if(a[i]> b[i+1]){
            res+= a[i]-b[i+1];
        }
    }
//    cout<<res<<endl ;
    res+=a[n-1];

    cout<<res<<endl ;
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
