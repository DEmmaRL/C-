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
    
    string s ;
    cin>>s;

    bool res = true ;
    int carrie = 0 ;
    if (s[sz(s) - 1] < '0' || s[sz(s) - 1] > '8' || s[0] != '1') {
        res = false;
    }
    
    for (int i = 0; i < sz(s) - 1; ++i) {
        if (s[i] < '1' || s[i] > '9') {
            res = false;
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