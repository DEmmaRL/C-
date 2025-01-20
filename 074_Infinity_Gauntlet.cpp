#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) (lli((s).size()))

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

void solve() {
    int a ;
    double b = 0.0;
    cin>>a ;
    b+=(a/(double)(2));
    cout<<b ;
    int tmp = b ;
    if((double)(tmp) == b){
        cout<<".0";
    }
    cout<<endl ;
}

int main() {
    IO;
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
