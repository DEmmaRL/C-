
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
    int n;
    cin>>n;
        
    string s ;
    cin>>s;

    map<char,char>mapa;
    set<char> st;
    string ans = "";

    vector<char>v ;

    for(auto e : s ){
        st.insert(e);
    }

    for(auto e : st) {
        v.pb(e);        
    }

    fore(i,0, v.size() ){
        mapa[ v[i] ] = v[ sz(v) - i - 1 ] ;
        
    }

    for(auto e : s ){
        ans+= mapa[e];
    }
    cout<<ans<<endl;


}


int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}