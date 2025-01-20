#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(lli i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

void solve() {
   int n ;
   cin>> n ;

   bool res = true ;
    vi v(n);
   fore(i,0,n){
    cin>>v[i];
   }

   fore(i,1,n){
    if( abs( v[i-1] - v[i] ) != 5 && abs( v[i-1] - v[i] ) != 7 ){
        res = false ;
    }
   }
    if(res){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

int main() {
    IO;
    int t; cin>>t ; while(t--)
        solve();
    

    return 0;
}
