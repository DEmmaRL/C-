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
    string s ;
    cin>>s ;

    bool zero = false , digit = false ;

    lli res = 1 ; 

    lli cont = 0 ;

    if(s[0] == '0' && s.size() > 1 ){
        cout<<"0"<<endl ;
        return ;
    } else if(s[0] == '0'){
        cout<<"0"<<endl ;
        return ;
    }


    fore(i,0, s.size()){
        if(s[i]== '?'){
            cont++;
        } else if(!digit) {
            digit = true ;
            if(cont){
                cont--;
                res*=9;
            }
        }
    }  
    if( cont && !digit ){
        cont--;
        res*=9;
    }
    while(cont--) res *= 10 ;

    cout<<res<<endl;
}

int main() {
    IO;
    int t ;
     cin>> t ; while(t--)
        solve();
    

    return 0;
}
