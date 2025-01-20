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
using vi = vector<lli>;
using pii = pair<int, int>;

const int MOD  = 1e9 + 7 ;

void solve(){
    
    lli n;
    cin>>n;
    vi v(n);
    bool dp[n];
    fore(i,0,n){
        cin>>v[i];
        dp[i]=false;
    }

    if(v[0] == v[n-1]){
        cout<<"NO"<<endl;
        return ;
    }

    cout<<"YES"<<endl;

    if( v[1] == v[n-1] ){

        dp[1] = true ;

    } else {
        dp[0] = true ;
    }
    string s ="";
    fore(i,0,n){

        if( dp[i] == false ){
            s+='R';
        } else{
            s+='B';
        }

    }
    cout<<s<<endl;


}


int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}