#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

void solve() {
   int n ;
   cin>>n;
   vi v(n), dp;

    unordered_set<int> st , a;

   fore(i,0,n){
    cin>>v[i];
    st.insert( v[i] );
   }

   for(int i=1; i <= n; ++i){
    if(st.find(i)==st.end()){
        dp.pb(i);
    }
   }
    int iter = 0 ;
   fore(i,0,n){
    if( a.find(v[i]) == a.end() ){
        a.insert(v[i]);
    } else {
        v[i] = dp[iter];
        iter++;
    }
   }

   fore(i,0,n){
    cout<<v[i]<<" ";
   }

    cout<<endl ;

}

int main() {
    IO;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
