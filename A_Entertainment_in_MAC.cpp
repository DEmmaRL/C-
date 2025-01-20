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
    cin>>n ;
    string s ;
    cin>>s;

    string res = s ;
    
    string tmp = s , e ;
    reverse(s.begin(), s.end()) ;

    tmp += s ; 
    e = s ;
    reverse(all(s));
    e+=s ;

   // reverse(all(tmp));
    //cout<<res<<" "<<tmp<<endl;
    

    res = min(res, min(tmp , e) ) ;

    cout<<res<<endl;

}

int main() {
    IO;
    int t; cin>>t ; while(t--)
        solve();
    

    return 0;
}
