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

    string s ;
    cin>>s;

    string tmp = s ;

    sort(all(tmp) ) ;

    int cont = 0 , cero = 0, is = 0 ;

    fore(i,0, sz(s)){

        if( tmp[i] != s[i] ){
            is = 1 ;
        }
        if(s[i]=='0') {
            //cout<<"ss";
            cero = 1 ;
        }

        if( s[i] =='1' ){
            //cout<<s[i]<<endl;
            //cout<<i<<endl;
            cont++;
        
            while(i < sz(s) && s[i] == '1'){
                //cout<<i<<endl;
                i++;
            }
            i--;
        }
    }

    if(cero == 1 && is)
    cout<<cont+1<<endl;
    else{
        cout<<1<<endl;
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