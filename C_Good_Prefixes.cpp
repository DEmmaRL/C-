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
    
    int n ;
    cin>>n;
    vi v(n);
    lli maximo = 0 , iter = 0, cont = 0 , carrie = 0 ;
    fore(i,0,n){
        cin>>v[i];
        carrie+= v[i];
        if( maximo <= v[i] ){
            carrie-=v[i];
            carrie+= maximo ;
            iter = i ;
            maximo = v[i];
        }

        if( maximo == carrie ){
            cont++;
        }
        
    }

    cout<<cont<<endl;

    
    
}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}