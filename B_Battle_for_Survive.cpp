
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
using pii = pair<int, int>;

void solve(){
    lli n ;
    cin>>n;
    lli res = 0 ;
    vi v(n);
    fore(i,0,n){
        cin>>v[i];
    }
    fore(i,0,n-2){
        res+= v[i];
    }

    v[n-2]-=res; v[n-1] -= v[n-2] ;

    cout<< v[n-1]<<endl;

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}