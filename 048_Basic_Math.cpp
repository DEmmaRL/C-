#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for(lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

void solve() {
    string s ;
    getline(cin,s );
    lli res = 0 ;
    string tmp = "" ;

    string sign = "*" ;
    fore(i,0, s.size()){
        if( s[i] == '+' or s[i] == '-' ){
            sign = ""; sign+= s[i];
        }
        if( s[i] >= '0' && s[i] <= '9' ){
            tmp+=s[i];
        } else if( s[i] == ' ' && tmp.size() ) {
            
            if( sign == "*" or sign == "+" ){
                res+=stoi(tmp);
                tmp = "" ;
            } else {
                res-=stoi(tmp);
                tmp = "" ;
            }
        }
    }

    cout<<s<<" "<<res<<endl;
}

int main() {
    IO;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
