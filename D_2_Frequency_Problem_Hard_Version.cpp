#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;
void solve() {
    int n  ;
    cin>>n ;
    vi v(n) ;
    int res = 0 ;

    fore(i,0,n){
        cin>>v[i];
    
    }

    int l= -1, r= -1 ;

    fore(i,0,n-1){
        if(v[i]!=v[i+1]){
            l=i;
            r=i+1;
            res = 2 ;
            break ;
        }
    }
    int maxi = 1 ;
    if(l==-1){
        cout<<"0"<<endl ;
    } else {
        unordered_map<int,int> mapa;
        mapa[v[l]]++;
        mapa[v[r]]++;

        while(r < n){
            int tmp = r+1 ;

            
        }
    }

}

int main() {
    IO;
    int t = 1 ;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
