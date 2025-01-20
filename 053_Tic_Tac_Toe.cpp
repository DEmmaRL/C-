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
    
    char a;
    cin>>a;

    vector<string> v(3);
    cin.ignore();
    fore(i,0,3){
        getline(cin, v[i]);
    }
    bool res = false ;
    fore(i,0,3){
        if( v[i][0] == a && ( v[i][1] == a && 
            v[ i ][ 2 ] == ' ' || v[i][2] == a && 
            v[ i ][ 1 ] == ' ') ){
            res = true ;
        }
        if( v[i][1] == a && v[ i ][ 2 ] == a && v[i][0] == ' ' ){
            res = true ;
        }
    }
    fore(i,0,3){
        if( v[0][i] == a && ( v[1][i] == a && 
            v[ 2 ][ i ] == ' ' || v[2][i] == a && 
            v[ 1 ][ i ] == ' ') ){
            res = true ;
        }
        if( v[1][i] == a && v[ 2 ][ i ] == a && v[0][i] == ' ' ){
            res = true ;
        }
    }
    if( v[0][0] == a && ( v[1][1] == a && v[2][2] == ' ' || v[1][1] == ' ' && v[2][2] == a ) ){
        res = true ;
    }

    if( v[2][0] == a && ( v[1][1] == a && v[0][2] == ' ' || v[1][1] == ' ' && v[0][2] == a ) ){
        res = true ;
    }

    if(res){
        cout<<"Yes you can."<<endl ;
    } else {
        cout<<"No you can't."<<endl ;
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
