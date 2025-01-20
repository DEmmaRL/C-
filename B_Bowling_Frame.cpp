#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(x) (int)size(x)

using namespace std;
using pii = pair<double, double>;
using vi = vector<lli> ;

lli f(lli a, lli b){

    lli res = 0 ;

    lli cur = 1 ;

    while(cur <= a){
        ++res;
        a-=cur;
        ++cur;
    }  
    while(cur <= b){
        ++res;
        b-=cur;
        ++cur;
    }  
    return res ;

}

void solve() {
    
    lli a, b ;
    cin>>a>>b;

    cout<<max(f(a,b), f(b,a))<<endl ;
    
}

int main() {
    IO;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}