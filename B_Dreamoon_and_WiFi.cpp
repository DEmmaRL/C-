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

double final = 0 , res = 0  , total = 0 , quest ;

double factoriales[11];

void f( double q, double curr , int cont){

    if(q == 0){
        if(curr == final) {
            res++;
        }
        total++;
        return ;
    }

    f( q - 1 , curr+1 , cont + 1 );

    f( q - 1 , curr-1 , cont );


}

void precalc(){
    factoriales[0] = 1 ;
    fore(i,1,11){
        factoriales[i] = factoriales[i-1] * i ;
    }
}

void solve() {
    string s, k ;
    cin>>s>>k;
    double  q =  0, init = 0 ;

    precalc();

    fore(i,0,s.size()){
        if(s[i] == '+') final++ ; 
        else final-- ;
    }

    fore(i,0,k.size()){
        if(k[i] == '+') init++ ; 
        else if(k[i]=='-') init-- ;
        else q++;
    }
    
    quest = q ;
    if(q == 0 ){
        if(init == final){
            cout<<setprecision(12)<<1.0<<endl;
        } else {
            cout<<setprecision(12)<<0.0<<endl;
        }
    } else {
        f( q , init , 0 );
        cout<<setprecision(12)<< res / total<<endl ;
    }
}

int main() {
    IO;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
