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

const int MAX = 1000 + 5 ;

char arr[MAX][MAX] ;
int dist[MAX][MAX] ;
bool vis[MAX][MAX] ;

int x[4] = { 0 , 1 , 0  , -1 } ;
int y[4] = { 1 , 0 , -1 ,  0 } ;

void solve() {
    
    int n , m ;
     cin>> n >> m ;

    vector< pair<int , pii > > v ;

    pii start , exit ;

    fore(i,0,n){
        fore(j,0,m){
            cin>>arr[i][j];

            if(arr[i][j] == 'S') start = {i,j};
            if(arr[i][j] == 'E') exit = {i,j};
            if(arr[i][j] <= '9' && arr[i][j] >= '0') 
                v.pb({ arr[i][j] - '0', {i,j}});
        }
    }

    int cont = 0 ;

    queue<pii>cola ;

    cola.push(exit);

    dist[exit.ff][exit.ss] = 0 ;
    vis[exit.ff][exit.ss] = true ;

    for(auto e : v ){
        dist[e.ss.ff][e.ss.ss] = 1e9 ;
    }

    while (!cola.empty())
    {
        pii frente = cola.front();
        cola.pop();

        fore(i,0,4){
            if( frente.ff + x[i] < n && frente.ff + x[i] >= 0 &&
                frente.ss + y[i] < m && frente.ss + y[i] >= 0 &&
                !vis[ frente.ff + x[i] ][ frente.ss + y[i] ] && 
                arr[ frente.ff + x[i] ][ frente.ss + y[i] ] != 'T'
                ){
                    vis[ frente.ff + x[i] ][ frente.ss + y[i] ] = true ;
                    dist[ frente.ff + x[i] ][ frente.ss + y[i] ] = dist[ frente.ff ][ frente.ss ] + 1 ;
                    cola.push({ frente.ff + x[i] , frente.ss + y[i] });
            }
        }
    }

    int distStart = dist[start.ff][start.ss] ;
    //cout<<distStart<<endl;
    for(auto e : v ){
        if( distStart >= dist[e.ss.ff][e.ss.ss] ){
            cont+=e.ff;
            
        }
        //cout<<"tenemos el valor : "<< e.ff<< " y distancia es "<< dist[e.ss.ff][e.ss.ss] << endl;
    }
    
    cout<<cont<<endl;


}

int main() {
    IO;
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
