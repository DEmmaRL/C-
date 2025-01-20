#include <bits/stdc++.h>
#define ENDL '\n'
#define fore(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second

using namespace std;

typedef long long int lli;
using pii = pair<lli, lli>;
using vi = vector<lli>;


const int MAXN = 1e4+7;  // Ajusta este valor según el problema específico

vector<int> adj[MAXN];
int pairU[MAXN], pairV[MAXN], dist[MAXN];
int U, V;

bool bfs() {
    queue<int> Q;
    for (int u = 1; u <= U; ++u) {
        if (pairU[u] == 0) {
            dist[u] = 0;
            Q.push(u);
        } else {
            dist[u] = INT_MAX;
        }
    }
    dist[0] = INT_MAX;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if (dist[u] < dist[0]) {
            for (int v : adj[u]) {
                if (dist[pairV[v]] == INT_MAX) {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return dist[0] != INT_MAX;
}

bool dfs(int u) {
    if (u != 0) {
        for (int v : adj[u]) {
            if (dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INT_MAX;
        return false;
    }
    return true;
}

int hopcroftKarp() {
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));
    memset(dist, 0, sizeof(dist));

    int matching = 0;

    while (bfs()) {
        for (int u = 1; u <= U; ++u) {
            if (pairU[u] == 0 && dfs(u)) {
                ++matching;
            }
        }
    }
    return matching;
}


void solve(){

    int n, m;
    cin>>n>>m;
    U = n ;
    V = m ;

    fore(i,1,n+1){
        int t;
        cin>> t ;

        while(t--){
           int tmp;
           cin>>tmp;

           adj[i].push_back(tmp);
           
        }

    }

    int match = hopcroftKarp();

    cout<<V - match<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL );

    cout.tie(NULL);
    
    solve();
}