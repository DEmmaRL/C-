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

    int n , m ;
    cin>>n >> m;

    string s ;
    cin>> s;

    map<char, int>mapa;

    fore(i, 0 , sz(s) ) {
        mapa[s[i]]++;
    }
    lli res = 0 ;
    for(char i = 'A' ; i <= 'G' ; ++i){
        if( mapa[i] < m ){
            res += m - mapa[i] ;
        } 
    }

    cout<<res<<endl;


}
 
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}