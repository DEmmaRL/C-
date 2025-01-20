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
    int n;
    cin>>n;
    map<int,int>mapa ;

    fore(i,0,n){
        int tmp;cin>>tmp;
        mapa[tmp]++;
    }

    int cont = 0 ;

    for(auto e:  mapa){
        cont+= e.ss / 2 ;
    }
    cout<<cont<<endl;

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
