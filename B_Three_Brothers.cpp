
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

const int MOD  = 1e9 + 7 ;

void solve(){
    
    map<int, int>mapa;
    int n ;
    cin>>n;

    mapa[n]++;
    cin>>n;
    mapa[n]++;
    if( mapa[1] == 0 ){
        cout<<1<<endl;
    }
    if( mapa[2] == 0 ){
        cout<<2<<endl;
    }
    if( mapa[3] == 0 ){
        cout<<3<<endl;
    }

}


int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}