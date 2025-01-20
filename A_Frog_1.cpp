#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using pii = pair<double, double>;
using vi = vector<lli> ;
#define INF 1e17 

void solve() {
    
    int n ;
    cin>> n ;
    
    vi v(n) , dp(n+1, INF);

    fore(i,0,n){
        cin>>v[i] ;
    }
    dp[0] = 0 ;
    fore(i,0,n){

        if( i + 1 < n ){
            dp[i+1] = min(dp[i+1], dp[i] + abs( v[i] - v[i+1] )) ;
        }
        if( i + 2 < n ){
            dp[i+2] = min(dp[i+2], dp[i] + abs( v[i] - v[i+2] )) ;
        }
    }
    cout<<dp[n - 1 ]<<endl;
}

int main() {
    IO;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}