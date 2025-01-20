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

void solve() {
    lli n, x, y; 
    cin>>n>>x>>y;

    vi v(n);

    lli sum = 0 ;

    fore(i,0,n){
        cin>>v[i];
        sum+=v[i];
    }

    sort(all(v));

    lli res = 0 ;   
    
    fore(i, 0, n - 1) {
        if ( sum - (v[i] + v[i + 1]) < x) 
            continue;

        lli tmpSum = sum - v[i];
        lli l = i + 1, r = n - 1, rangex = -1;
        while ( l <= r ) {
            lli mid = ( l + r ) / 2;
            if (tmpSum - v[mid] >= x) {
                rangex = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (rangex == -1) continue;

        l = i + 1, r = rangex;
        lli rangey = -1;
        while ( l <= r ) {
            lli mid = ( l + r ) / 2;
            if (tmpSum - v[mid] > y) {
                l = mid + 1;
            } else {
                rangey = mid;
                r = mid - 1;
            }
        }

        if (rangey == -1) continue;

        res += max(0LL, rangex - rangey + 1);
    }
    cout<<res<<endl ;
    // RECUERDA AL FINAL HACER RANGEX = MAX(RANGEX , I ) PARA NO REPETIR PARES
}

// 3 4 6 6
// Sum = 19

int main() {
    IO;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
