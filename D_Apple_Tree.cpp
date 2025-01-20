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

const int MAX = 1e5+7;

vector<vector<int> > graph ;

int dfs( int c , vi &dp, vector<bool> &vis ){
   // cout<<"AAAAA "<< c << endl ;
    for( auto e : graph[c] ){
        if( !vis[ e ] ){
            vis[e] = true ;
            dp[c] += dfs(e , dp , vis ) ;
        }
    }

    if(dp[c] == 0 ) dp[c] = 1 ;
    //cout<<"la respuesta para "<<c<<" es "<< dp[c]<<endl;
    return dp[c] ;

}

void solve() {
    
    int n ; 
    cin>>n ;

    graph.clear();
    graph.resize(n);

    fore(i,0,n-1){
        int a, b;
        cin>>a>>b;
        --a, --b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int q; cin>>q;
   // cout<<"Querie "<< q << endl;

    vi dp(n,0);

    vector<bool> vis(n,0) ;

    vis[0] = true ;

    dfs(0 , dp, vis) ;

    while(q--){
        int a, b;
        cin>>a>>b;
        --a,--b;

        cout<<dp[a]*dp[b]<<endl;

    }

}

int main() {
    IO;
    int t = 1; 
    cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}
