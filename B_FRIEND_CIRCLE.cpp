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
using pii = pair<lli, lli>;

const int MAX = 1e9+7;

const int INF = 1e9 ;
class DisjointSet {
public:
    vector<int> parent, minimo, maximo, size ;
    int cont  ;

    DisjointSet(int n) : parent(n), size(n, 1) {
        cont = 0 ;
        for (int i = 0; i < n; i++) {
            parent[i] = -1 ;
        }
    }

    void join(int a, int b) {
        int find_a = find(a), find_b = find(b);

        parent[find(b)] = find(a);
        if(find_a != find_b)
        size[find_a] += size[find_b];
    }

    int find(int a) {
        if(parent[a]==-1)
        {
            return -1 ;
        }
        return a == parent[a] ? a : parent[a] = find(parent[a]);
    
    }
    void insert(int a)
    {
        parent[a] = a ;
    }

    int connectedComponents(int a) {
        return size[find(a)];
    }
};

void solve(){

    int n ; 
    cin>>n ;
    DisjointSet dsu = DisjointSet( n * 2 ) ;

    map<string, int> mapa ;

    fore(i,0,n){

        string a, b ;
        cin>>a>>b ;
        int tmp = mapa.size() + 1 ;
        if(mapa[a] == 0  ){
            mapa[a] = tmp ;
        }
        tmp = mapa.size() + 1;
        if(mapa[b] == 0  ){
            mapa[b] = tmp ;
        }

        if( dsu.parent[ mapa[a] ] == -1 ){
            dsu.insert( mapa[a] ) ;
        }
        if( dsu.parent[ mapa[b] ] == -1 ){
            dsu.insert( mapa[b] ) ;
        }

        dsu.join( mapa[a], mapa[b] );

        cout<< dsu.size[ dsu.parent[mapa[a]] ] << endl ;

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