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


void solve(){

    int n ;
    cin>>n;

    vi v(n);

    fore(i,0, n){
        cin>>v[i];
    }
    sort(all(v));

    vi res ;

    res.pb(v[0]);

    fore(i,0, n){

        if( v[i] % res[0] != 0 ){
            res.pb(v[i]);
            break;
        }

    }

    if(sz(res) == 1 ){ 
        res.pb(v[0]);
    }

    bool r = true ;

    fore(i,0,n){
        if( v[ i ] % res[0] != 0 && v[ i ] % res[1] != 0 ){
            r = false ;
        }
    }

    if(r){
        cout<<"Yes"<<endl;
    } else 
    {
        cout<<"No"<<endl;
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