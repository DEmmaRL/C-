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

#define K 10

vi g[ 1 << K ] ;
int n ;

int F[K][1<<K], D[1<<K] ;

void lca_dfs( int x ){
    fore( i,0,g[x].size() ){
        int y = g[x][i];
        if(y==F[0][x]) continue;
        F[0][y] = x ;
        D[y] = D[x] + 1 ;
        lca_dfs(y);
    }
}
void lca_init(){
    D[0] = 0 ; F[0][0]= -1 ;
    lca_dfs(0);
    fore(k,1,K) fore(x,0,n){
        if( F[k-1][x] < 0 ) F[k][x] = - 1 ;
        else F[k][x] = F[k-1][F[k-1][x] ];
    }
}

int lca(int x , int y){
    if(D[x]< D[y]) swap(x,y);

    for(int k=K-1 ; k >= 0; --k)
        if(D[x] - (1<<k)>=D[y])
        x = F[k][x];
    if(x==y) return x ;
    for(int k = K-1; k>=0; --k){
        if(F[k][x]!= F[k][y])
        x = F[k][x] , y = F[k][y];
    }
    return F[0][x];
}

void clearlca(){
    fore(i,0,n){
        g[i].clear();
    }

    fore( i, 0, K ){
        fore(j,0,1<<K)
            F[i][j] = 0 ;
    }
}

void solve(int t) {
    clearlca();
    cin>>n ;

    fore(i,0,n){

        int tam;
        cin>>tam;

        fore(j,0,tam){
            int curr ;
            cin>>curr;
            curr--;
            g[i].pb(curr);
        }

    }
    lca_init();
    int q ;
    cin>>q ;
    
    cout<<"Case "<<t<<":"<<endl;

    while(q--){
        int a, b;
        cin>>a>>b;--a;--b;

        cout<< lca(a,b) + 1<<endl;
    }
    return ;

}

int main() {
    IO;
    
    int t = 1;
    cin>>t;
    
    fore(i,1,t+1) {
        solve(i);
    }

    return 0;
}
