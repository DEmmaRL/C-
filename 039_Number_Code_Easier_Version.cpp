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
    
    int n ;
    cin>>n ;
    cin.ignore();
    
    map<char,char> mapa ;

    mapa['0'] = 'o' ;
    mapa['1'] = 'i' ;
    mapa['3'] = 'e' ;
    mapa['4'] = 'a' ;
    mapa['5'] = 's' ;
    mapa['7'] = 't' ;


    fore(i,0,n){
        string s ;
        getline(cin,s);
        fore(j,0, s.size()){
            if(mapa[s[j]]!=0){
                s[j] = mapa[s[j]];
            }
        }
        cout<<s<<endl ;
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
