#include <bits/stdc++.h>
#define ENDL '\n'
#define fore(i,a,b) for(int i=a;i<b;i++)

#define lli long long int
#define vi vector<lli>

#define pb push_back


using namespace std;

int n , p ;

const int MAXN = 100000 + 7 ;

vector<int> g[ MAXN ] ;

int dist[2][MAXN];

bool vis[2][MAXN] ;

lli diametro(){

    vis[0][0] = true  ;

    queue<int>cola ;

    cola.push(0) ;
    
    dist[0][0] = 0 ;

    int fin = 0 , tam = 0 ;

    while(!cola.empty()){
        int frente = cola.front() ;
        cola.pop() ;

        for(auto e : g[frente] ) {
            if(!vis[0][e]){
                vis[0][e] = true ;
                cola.push( e );
                dist[0][e] = dist[0][frente] + 1 ;

                if(tam < dist[0][e] ){
                    tam = dist[0][e] ;
                    fin = e ;
                }
            
            }
        }
    }

    cola.push(fin) ;
    
    dist[1][fin] = 0 ;

    vis[1][fin] = true ;

    while(!cola.empty()){
        int frente = cola.front() ;
        cola.pop() ;

        for(auto e : g[frente] ) {
            if(!vis[1][e]){
                vis[1][e] = true ;
                cola.push( e );
                dist[1][e] = dist[1][frente] + 1 ;

                if(tam < dist[1][e] ){
                    tam = dist[1][e] ;
                }
            
            }
        }
    }

    return tam ;

}


void solve(){
    
    cin>>n>>p;

    fore(i,0,n-1){
        int a, b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }

    int res = diametro(); 

    res *= p / (n-1) ;

    res += p %  (n-1) ;

    cout<<res<<endl;

}

int main(){
    solve();
    return 0;
} 