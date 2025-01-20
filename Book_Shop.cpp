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
using vi = vector<int>;
using pii = pair<int, int>;

// Función para resolver el problema de knapsack 0/1 usando optimización de espacio
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Crear dos arrays para el estado actual y el previo
    vector<int> prev(W+1, 0), curr(W+1, 0);

    // Llenar los arrays
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i-1] <= w) {
                curr[w] = max(prev[w], prev[w - weights[i-1]] + values[i-1]);
            } else {
                curr[w] = prev[w];
            }
        }
        // Copiar el estado actual al estado previo
        prev = curr;
    }

    // El valor máximo se encuentra en prev[W]
    return prev[W];
}


void solve(){
    int n, x ;
    cin>>n>>x;

    vector<int>v(n) , w(n);

    fore(i,0,n) cin>>w[i];

    fore(i,0,n) cin>>v[i];

    cout<<knapsack( x , w , v , n ) <<endl;
}
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}