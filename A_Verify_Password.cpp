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

const int MOD  = 1e9 + 7 ;

void solve(){
    int n ;
    cin >> n ;
    //cout<<n<<endl;

    string s ;
    cin>>s ;

    int c = 0 ;
    
    vi a, b;
    bool res = true ;

    fore(i,0,n){

        if( s[i]>='a' && s[i] <='z' ){
            a.pb(s[i]);
            c = 1 ;
        } else if( c ) {
            res = false ;
            break;
        } else{
            b.pb(s[i]);
        }

    }

    fore(i,1,sz(a)){
        if(a[i]<a[i-1]){
            res = false ;
            break;
        }
    }

    fore(i,1,sz(b)){
        if(b[i]<b[i-1]){
            res = false ;
            break;
        }
    }

    if(res){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
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