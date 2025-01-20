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
using vi = vector<int>;
using pii = pair<lli, lli>;

void solve() {
    lli n, k, res = 0 ;
    cin >> n >> k;
    
    bool band = true ;
    while(band){

        lli tmp = k ;
        band = false; 
        while( (tmp * k ) <= n && (tmp * k ) > 1 ){
            tmp = tmp * k ;
        }

        if( tmp <= n && tmp > 1 ){
            band = true ;
            //cout<<tmp<<endl;
            n-= tmp;
            res++;
        }
    }
    res+= n ;
    cout<<res<<endl;
}

int main() {
    IO;
    int t = 1; cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}
