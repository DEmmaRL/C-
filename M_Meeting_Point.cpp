#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define f first
#define s second
#define fore(i,a,b) for(lli i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

lli n , INF = 1e18, init, goal;
// each pair has: {node,distance}
vector< vector< pair<lli , lli> > > g ;
vector<bool>vis;
vector<unordered_map<int,lli> > distancias ;

void shortest_path(){
    vector<lli> dist(n , INF);
    vector<lli> padre(n , INF);
    dist[init]=0;
    priority_queue<pair<lli , lli>, vector<pair<lli , lli > >, greater<pair<lli , lli >  >  > pq;

    pq.push({init,0});
    while(!pq.empty()){
        pair<lli , lli> cur = pq.top();
        pq.pop();
        if(dist[cur.s] != cur.f) continue;

        for( auto node : g[cur.s] ){
            lli nwDist = dist[cur.s] + node.second;

             if( dist[node.f] == INF or (dist[node.f] > nwDist) ){                
                padre[node.f] = cur.s;
                dist[node.f] = nwDist;
                pq.push({nwDist,node.f});
             }
        }
    }
    

    vector<int>tree[n] ,  res ;

    fore(i,0,n){
        if(padre[i] == INF) continue ;
        tree[ padre[i] ].pb(i);
        //cout<<padre[i]+1<<" es padre de "<<i+1<<endl;
   
    }


    for(auto e : tree[goal]){
        //cout<<e+1<<endl;
        lli currDist = dist[e] ;

        queue< pii > cola ;

        cola.push({e, currDist});

        //cout<<e+1<<" "<<currDist<<endl;

        if(currDist == dist[goal] * 2){
            res.pb(e);
        }

        while( !cola.empty() ){
            pii frente = cola.front();
            cola.pop();

            for(auto a : tree[frente.f] ){
                lli newDist = frente.s + distancias[frente.f][a];
                if( newDist < dist[goal] * 2 )
                    cola.push({a,newDist});
                if( newDist == dist[goal] * 2 ){
                    res.pb(a);
                }
            }

        }


    }

    sort(all(res));

    for(auto e : res ){
        cout<<e+1<<" ";
    }
    if(res.size() == 0 ){
        cout<<"*";
    }
    cout<<endl;

}

void solve() {
    cin>>n;
    int m ;
    cin>>m;
    cin>>init>>goal;
    init--, goal--;
    g.clear();
    g.resize(n);
    distancias.clear();
    distancias.resize(n);
    while(m--){
        lli u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        g[u].pb({v,d});
        g[v].pb({u,d});
        distancias[u][v] = d ;
        distancias[v][u] = d ;
    }

    shortest_path();
}

int main() {
    IO;
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
