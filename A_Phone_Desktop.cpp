#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

const int MAX = 1e9+7;

void solve(){

    int a, b , res = 0 ;
    cin>>a>>b;
    if(b)
        res = (b/2) + (b%2) ;

    int extra = 0  ;
    
    if(b) extra = (b/2) * 7 ;
    
    if(b > 1 && b%2){
        extra+=4;
    }

    if(b == 1 ) extra = 11 ;

    if( a - extra <= 0 ){
        cout<< res <<endl;
    } else {
        int resto = a - extra;

        resto/= 15 ;

        if((a - extra) % 15 != 0 ) resto++;

        cout<<resto + res <<endl ;
    }

}
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}