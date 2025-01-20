#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) (lli((s).size()))

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

void solve() {
    bool res = true ;

    int n ; cin>>n;

    vi a(n), b(n);

    bool tmp = false ;

    int cont = 0 ;

    fore(i,0,n){
        cin>>a[i];
    }

    fore(i,0,n){
        cin>>b[i];
    }

    fore(i,0,n){
        
        if( a[i] - cont  < b[i] ){
            if(tmp){
                res = false ;
                break ;
            } else {
                cont = b[i] - ( a[i] - cont ) ;
                tmp = true ;
            }
        }

    }
    if(res){
        tmp = false ;
        cont = 0 ;
    for(int i = n-1; i >= 0 ; --i){
        
        if( a[i] - cont  < b[i] ){
            if(tmp){
                res = false ;
                break ;
            } else {
                cont = b[i] - ( a[i] - cont ) ;
                tmp = true ;
            }
        }

    }
    }
    if(res ){
        cout<<"YES"<<endl ;
    } else {
        cout<<"NO"<<endl ;
    }

}

int main() {
    IO;
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
