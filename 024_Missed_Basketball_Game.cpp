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

    string a ,  b ;
    cin>>a>>b;

    int resa = 0 , resb = 0 ;

    int tmp1 , tmp2 , c , d ;
    cin>>tmp1>>tmp2;
    cin>>c>>d;

    tmp1-=c ;
    tmp2-=d ;

    resa = c * 3 ;
    resb = d * 3 ;

    cin>>c>>d;

    tmp1-=c ;
    tmp2-=d ;

    resa += c ;
    resb += d ;
   // cout<<tmp1<<" "<<tmp2<<endl ;

    resa+=tmp1*2;
    resb+=tmp2*2;
//cout<<resa<<" "<<resb<<endl;
    if(resa>resb){
        cout<<a<<endl ;
    } else {
        cout<<b<<endl ;
    }


}

int main() {
    IO;
    int t = 1 ;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

