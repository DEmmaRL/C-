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

const int MAX = (2 * 1e5) + 7 ;

int arr[ MAX ];

int f(int n){

    int res = 0 , x = 10;

    while(n){

        res+= n%x;
        n/=x;

    }
    return res ;

}

void solve() {
	
    int n ;
    cin>>n;

    cout<<arr[n]<<endl ;

}
 

int main() {
    IO;
    
    arr[0] = 0 ;

    fore(i,1,MAX){

        arr[i] = arr[i-1] + f(i); 

    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
