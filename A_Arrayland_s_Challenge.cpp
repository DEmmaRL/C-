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

const int MAX = 1e4+7;

int dp[MAX][MAX] ;

vi v ;

int INF= 1e9 ;

int res( int l , int r ){

    if( dp[l][r] != -1 ) return dp[l][r];

    if( l == r ) return INF ;
    

    if(l + 1 == r ) {
        dp[l][r] = abs( v[l] - v[r] ) ;
        return dp[l][r];
    } 

    dp[l][r] = min( abs( v[l] - v[r] ) , min( res(l+1, r) , res( l , r-1 ) ) ) ;

    return dp[l][r];
}




void solve(){

    fore(i,0,MAX){
        fore(j,0,MAX){
            dp[i][j] = -1 ; 
        }
    }
    
    int n; 
    cin>>n;

    v.resize(n);

    fore(i,0,n){
        cin>>v[i];
    }

    for(int i=0; i < n ; ++i ){

        for(int j = i + 1 ; j < n ;++j){

            //res(l,r) = min(abs(v[l]-v[r]),res(l+1,r),res(l,r-1));

            dp[i][j] = res(i,j) ;

        }
    }


    int q ;
    cin>>q;
    while (q--)
    {
        int l , r ;
        cin>>l>>r;
        l--;r--;

        cout<<dp[ l ][ r ] << ENDL ;
    }
    

}
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}