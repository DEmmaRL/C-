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

#define K 17

vi g[ 1 << K ];
int n, root = 0;

int F[K][1<<K], D[1<<K];

vector<int> hijos[1<<K];

void lca_dfs(int x) {
    fore(i, 0, g[x].size()) {
        int y = g[x][i];
        if (y == F[0][x]) continue;
        F[0][y] = x;
        //cout<<"el padre de "<<y<<" es "<< x <<endl;
        D[y] = D[x] + 1;

        hijos[x][1]++; 

        lca_dfs(y);

        fore(j, 0, hijos[y].size()) {
            hijos[x][j+1] += hijos[y][j];
        }
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

void solve() {
    cin >> n;
    fore(i, 0, n) {
        hijos[i].resize(K, 0);
    }
    
    fore(i, 0, n) {
        int tmp;
        cin >> tmp;
        g[tmp].pb(i+1);
    }

    n++;  

    D[0] = 0; 
    lca_init();
    //cout<<hijos[F[1][6]][1+1];

    int q ;
    cin>>q ;
    while(q--){

        int a, b ;
        cin>>a>>b; 
       // cout<<"consultamos el nivel "<<b-1<<" de "<< a <<" en pos "<< b<<endl;
       // cout<<" el ancestro es "<< F[b-1][a]<<endl;
        if(F[b-1][a] >= 1 )
        cout<<hijos[F[b-1][a]][b] - 1 << " ";
        else 
        cout<<0<<" ";
    }

}


int main() {
    IO;
    solve();
    return 0;
}
