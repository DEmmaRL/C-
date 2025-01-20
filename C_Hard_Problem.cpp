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
   int n ;
   cin>> n;

   int a, b, c ;
   cin>>a>>b>>c;

   int res = 0 ;

   int r1=n, r2 = n ;

    res+= min(r1, a);
    r1= r1- min(r1, a) ;
    res+= min(r2, b);
    r2= r2- min(r2, b) ;
    
    if(r1 && c ){
        res+= min(c, r1);
        c-=min(c, r1); 
    }
    if(r2 && c ){
        res+= min(c, r2);
        c-=min(c, r2); 
    }
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
