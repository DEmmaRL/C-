
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
    int n ;
    cin>>n;
    for( int i = 0 ; i < (n/5) + (n%5>=1) ; ++i ){
        cout<<'a';
    }
    for( int i = 0 ; i < (n/5) + (n%5>=2) ; ++i ){
        cout<<'e';
    }
    for( int i = 0 ; i < (n/5) + (n%5>=3) ; ++i ){
        cout<<'i';
    }
    for( int i = 0 ; i < (n/5) + (n%5>=4) ; ++i ){
        cout<<'o';
    }
    for( int i = 0 ; i < ((n/5)) ; ++i ){
        cout<<'u';
    }
    cout<<endl;
}


int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}