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

const int MAX = 1e9+7;

lli x, y, z ;

lli f(lli a, lli b , lli c) {

    return ( x/a ) * (y / b ) * (z / c ) ;

}

void solve(){

    lli a, b, c;

    cin>>x>>y>>z;

    cin>>a>>b>>c ;

    lli res = 0 ;

    res = max(res, f( a , b , c ) ) ;
    res = max(res, f( a , c , b ) ) ;
    res = max(res, f( b , a , c ) ) ;
    res = max(res, f( b , c , a ) ) ;
    res = max(res, f( c , b , a ) ) ;
    res = max(res, f( c , a , b ) ) ;

    cout<<res<<endl;
}
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}