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

lli n,k;

bool check(vi &v , lli x){
    lli cont = 0 ;

    fore(i,0,v.size()){

        cont+= v[i] / x ;
        if(cont >= k) return true ;
    }
    return false ;
}

void solve() {
    
    cin>>n>>k;
    vi v(n);

    fore(i,0,n){
        cin>>v[i];
    }

    lli l = 0 , r = 1e12 ;

    while( r - l > 2 ) {
        lli mid = (l+r) / 2 ;
        if( check( v , mid ) ) l = mid ;
        else r = mid - 1 ;

    }

    for(lli i = r ; i >= l ; --i){
        if(check(v, i)) {
            cout<<i<<endl;
            return ;
        }
    }

}   

int main() {
    IO;
    //int t = 1; cin>>t ; while(t--) 
        solve();

    return 0;
}
