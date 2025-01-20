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

const int MOD  = 1e9 + 7 ;

void solve(){
    int n , k ; 
    cin>>n>>k;

    vector<int>v(n) , dp(k+1, 0);

    fore(i,0, n){
        cin>>v[i];
    }
    dp[0]=1 ;
    fore(i, 1, k+1){
        fore(j,0, n){
            if( i - v[j] >= 0 ){
                dp[ i ] = ( dp[ i - v[j] ] + dp[ i ] ) % MOD ;
            }
        }
    }

    cout<<dp[k]<<endl;

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}