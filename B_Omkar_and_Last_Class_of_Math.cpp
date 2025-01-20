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

void solve(){

    int n ; 
    cin >> n ;

    int res = -1 ;

    for(int i=2; i*i<= n ; ++i){
        if( n % i == 0 ){
            res = max( res , max(i, n/i) ) ; 
        }
    }

   if( res == -1 ){
    cout<<n-1<<" "<<1<<endl;
   } else{
    cout<<res<<" "<<n - res <<endl;
   }

}
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}