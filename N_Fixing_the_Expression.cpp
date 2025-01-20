#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using pii = pair<double, double>;

void solve() {
    
    string s ;
    cin>>s; 

    int a = s[0] - '0' ;
    int b = s[2] - '0' ;

    if( s[1] == '<' ){
        if( a > b ){
            s[1] = '>' ;
        } else if( a == b ){
            s[1] = '=' ;
        }
        cout<<s<<endl;
    }
    else if( s[1] == '>' ){
        if( a < b ){
            s[1] = '<' ;
        } else if( a == b ){
            s[1] = '=' ;
        }
        cout<<s<<endl;
    } else {
        if( a != b ){
            s[0] = (char)(b + '0') ;
        }
        cout<<s<<endl;
    }

}

int main() {
    IO;
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
