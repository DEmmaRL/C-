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
    int n ;

    cin>>n;

    char arr[n][n] ;

    int dp[n][n] ;

    fore(i, 0 , n){

        fore(j, 0 , n ){
            cin>>arr[i][j];
            dp[i][j] = 0 ;
        }

    } 
    if(arr[0][0] == '.')
    dp[0][0] = 1 ;

    fore(i,1,n){
        if( arr[i][0] !='*' ){
            dp[i][0] = dp[0][0] ;
        } else {
            break ;
        }
    }
    fore(i,1,n){
        if( arr[0][i] !='*' ){
            dp[0][i] = dp[0][0] ;
        } else {
            break ;
        }
    }

    fore(i,1 , n){
        fore(j,1,n){
            if( arr[i][j] != '*'  ){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) %  MOD ;
            }
        }
    }
    cout<<dp[n-1][n-1];
    

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}