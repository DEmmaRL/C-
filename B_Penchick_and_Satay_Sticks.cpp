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
    int n;
    cin>>n;
    vi v(n);

    fore(i,0,n){
        cin>>v[i];
    }
    bool res = true ;
    fore(i,0,n){
        if( v[i] != i+1 && i + 1 < n && v[i+1] == i+1 
                && abs(v[i] - v[i+1]) == 1 ){
                swap(v[i], v[i+1]);
        }
    }
    fore(i,0,n){
        if( v[i] != i+1 && i - 1 >=0 && v[i-1] == i+1 
                && abs(v[i] - v[i-1]) == 1 ){
                swap(v[i], v[i-1]);
        } else {
            res = false ;
        }
    }
    fore(i,0,n){
        cout<<v[i]<<" ";
    }
    cout<<endl ;

    if(res){
        cout<<"YES"<<endl ;
    } else {
        cout<<"NO"<<endl ;
    }
    
}

int main() {
    IO;
    int t = 1; 
    cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}
