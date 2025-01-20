#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using pii = pair<double, double>;

void solve() {
    lli n,a=0,b=0,c=0,s=0;

    cin>>n;
    fore(i,0,n){
        cin>>a;
        if(a<0){
            s=s - a-1;
            ++b;
        }
        if(a>0)
            s= s +a-1;
        if(a==0){
            c++;
            s++;
        }
    }
    if(b%2!=0 && c==0)
        s+=2;
    cout<<s<<endl;
}

int main() {
    IO;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
