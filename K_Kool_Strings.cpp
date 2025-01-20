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
    int  k; 
    cin>>k ; 
    string s ;
    cin>>s ;
    int res = 0 ;
    if(k == 2){

        int cont1 = 0 , cont2 = 0 ;
        
        fore(i,0,s.size()){
            if(s[i] - '0' != i%2){
                cont1++;
            }
        }
        fore(i,0,s.size()){
            if(s[i] - '0' == i%2){
                cont2++;
            }
        }
        res = min(cont1, cont2);
        if( cont1 < cont2 ){
        
            fore(i,0,s.size()){
                if(s[i] - '0' != i%2){
                    s[i] = '0' + abs( (s[i] - '0') - 1 );
                }
            }   
        
        } else {
            fore(i,0,s.size()){
                if(s[i] - '0' == i%2){
                    s[i] = '0' + abs( (s[i] - '0') - 1 );
                }
            }
        }
    } else{ 
        int cont = 1 , curr = s[0] - '0';
        fore(i,1,s.size()){
            if( s[i] - '0' == curr  ){
                cont++;
                if( cont == k ){
                    res++;
                    if( i + 1 < s.size() ){
                        if(s[i+1] == s[i] ){
                            s[i] = '0' + abs( (s[i] - '0') - 1 ); 
                        } else {
                            s[i-1] = '0' + abs( (s[i-1] - '0') - 1 ); 
                            cont = 1 ;
                        }
                    } else {
                        s[i] = '0' + abs( (s[i] - '0') - 1 );
                        cont = 1 ;
                    }
                }
            } else {
                cont = 1 ;
            }
            curr = s[i]- '0';
        }
    }

    cout<<res<<" "<<s<<endl;
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
