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
    getline(cin,s);

    string a = "" , b  = "" ;

    vector<string>v ;
    string tmp = "" ;
    fore(i,0,s.size()){

        if( s[i] == ' ' ){
            v.pb(tmp) ;
            tmp = "" ;
        } else{
            tmp+=s[i];
        }

    }
    v.pb(tmp);

    fore( i,v.size() / 2, v.size() ){
        cout<<v[i]<<" ";
    }

    fore( i, 0, v.size() / 2 ){
        cout<<v[i]<<" ";
    }

}

int main() {
    IO;
    int t = 1;
    //cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
