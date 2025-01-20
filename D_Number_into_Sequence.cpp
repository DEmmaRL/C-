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
	
    lli n ;
    cin>>n;

    vi div ;

    for(int i=1; i * i <= n ; ++i){
        if( n % i == 0 ){
            div.pb(i);
            if( n / i != i ){
                div.pb(n/i);
            }
        }
    }
    sort(all(div));

    vi v ;
    lli iter = 0 , tmp = n ;

    while( tmp != 1 ){
        while(  ){

        }
    }

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