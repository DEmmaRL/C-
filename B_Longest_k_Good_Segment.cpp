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

const int MAX = 1e6 + 5 ;

int dp[MAX] ;

void solve() {
    int n, k ;
    cin>>n>>k;
    vi v(n);
    fore(i,0,n){
        cin>>v[i];
    }
    int res = 0 , l = 0 , r = 0 , x = 0 , y = 0 ;
    int cont = 0 ;


    while( r < n && cont <= k ){
        
        if( dp[ v[r] ] == 0  ){
            cont++;
        }
        dp[ v[r] ]++;
        if(cont <= k ){
            if( (r - l) + 1 > res ){
              //  cout<<l<<" "<<r<<endl;
                res = (r - l) + 1 ;
                x = l ;
                y = r ;
            }
        }
        else{
            while (cont>k && l < r )
            {
                dp[v[l]]--;
                if(dp[v[l]]==0) {
                    l++;
                    cont--;
                    break;
                }
                l++;
                
            }
            //cout<<l<<" a "<<r<<endl;
            
        }
        r++;
    }
    cout<<x+1<<" "<<y+1<<endl;

}

int main() {
    IO;
    int t = 1; 
    //cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}
