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

const int MAX = 1e9+7;

void solve(){

    vi v(3);

    fore(i,0, 3){
        cin>>v[i];
    }
    sort(all(v));

    if( (v[0] + v[1] + v[2] ) % 2 == 1 ){
            cout<<-1<<endl;
    } else {

        int res = min( (v[0] + v[1] + v[2] )/ 2  , v[0] + v[1] ) ;

        cout<<res<<endl;
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