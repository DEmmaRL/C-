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
using vi = vector<lli>;
using pii = pair<lli, lli>;

void solve() {
    int n, k ;
    cin>>k>>n;

    lli res = 0 ;

    unordered_map<int,int> mapa ;
    fore(i,0,n){
        int a, b ;
        cin>>a>>b;
        mapa[a]+= b;
    }

    vector< int > v ;

    for( auto e : mapa ){
        v.pb( e.ss );
        //cout<<e.ff<<" "<<e.ss<<endl;
    }
    sort( v.rbegin(), v.rend());

    for(int i=0; i < k &&  i < v.size(); ++i){ 
        res+= v[i] ;
    }
    cout<<res<<endl ;
}

int main() {
    IO;
    int t; cin>>t ; while(t--)
    solve();
    

    return 0;
}
