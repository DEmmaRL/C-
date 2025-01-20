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
using vi = vector<lli>;
using pii = pair<int, int>;

const int MOD  = 1e9 + 7 ;

void solve(){
    
    lli x, y, z, k;
    cin>>x>>y>>z>>k;

    lli res = 0 ;

    if( x * y * z < k ){
        cout<<0<<endl;
        return ;
    } else if( x * y * z == k ){
        cout<<1<<endl;
        return ;
    }

    for(lli i = 1 ; i <= x ; i++ ){

        for( lli j = 1 ; j <= y && j * i <= k ; ++j ){

            if( k % (j*i) == 0 && k / ( j * i ) <= z ){
            
                lli tmp =  ( (x - i) + 1 ) * ( ( y - j ) + 1 ) * ( (z - ( k / ( j * i ) ) ) + 1 ) ;

                res = max(res, tmp);
            }
        }
    }

    cout<<res<<endl;

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}