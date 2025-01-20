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

    int n, k ;

    cin>>n>>k;

    if( k == 1){
        fore(i,0,n){
            cout<<i+1<<" ";
        }
        cout<<endl ;
        return ;
    }
    
    int p = n / k ;

    vi extra , pilas[p]; 
    int tmp = n ;

    fore(i,0, (int)(n%k) ){ 
        extra.pb(tmp);
        --tmp;
    }

    fore( i , 0, extra.size() ){
        cout<<extra[i]<<" ";
    }

    queue<int> cola ;

    fore(i,0,p){
        cola.push(i+1);
        //cout<<i+1<<endl ;
    }

    int cont = extra.size() , init = cola.size() ;
    
    fore( i, init , tmp ){

        if( (cont) % p == 0 && cont != 0 ){
            cout<<cola.front()<<" ";
            cola.pop();
        }
        cout<<i+1<<" " ;
        cont++;
    }  

    while(!cola.empty()){
        cout<<cola.front()<<" "; cola.pop();
    }  

    cout<<endl ;

}

int main() {
    IO;
    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

