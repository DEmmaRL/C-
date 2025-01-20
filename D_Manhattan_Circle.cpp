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
    
    int n, m;
    cin>>n>>m;

    char arr[n][m];

    fore(i,0,n){
        fore(j,0,m){
            cin>>arr[i][j];
        }
    }

    int maximo = 0 , iter = 0 ;

    fore(i,0,n){
        int cont = 0 ;
        fore(j,0,m){
            if( arr[i][j] == '#' ){
                cont++;
            }
        }

        if(cont > maximo){
            maximo = cont ;

            iter = i ;
        }
    }

    pair<int, int> res ;
    int cont = 0 ;
    for(int i=0; i < m ; ++i ){

        if( arr[iter][i] == '#' ){
            cont++;

            if( cont == ( maximo / 2 ) + 1  ){
                res.ff = iter ;
                res.ss = i ;
            }
        }

    }

    cout<<res.ff + 1 <<" "<<res.ss + 1<<endl;

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}