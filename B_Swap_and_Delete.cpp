#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) (lli((s).size()))

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

#define LAST_DIGIT(num) (num.back() - '0')
#define SUM_DIGITS(num) (accumulate(all(num), 0LL, [](lli a, char b) { return a + (b - '0'); }))
#define LAST_BLOCK(num, x) (stoi(num.substr(max(0LL, sz(num) - (x)), min(sz(num), lli(x)))))

void solve(){
    string s ;
    cin>>s ;

    int cero = 0 , uno = 0 ;

    fore(i,0,s.size()){
        if(s[i]=='0'){
            cero++;
        } else {
            uno++;
        }
    }
    int cont = 0 ;

    fore(i,0,s.size()){
        if(s[i]=='0'){
            if(uno){
                cont++;
                uno--;
            } else {
                break ;
            }
        } else {
            if(cero){
                cont++;
                cero--;
            } else {
                break ;
            }
        }
    }

    cout<< s.size() - cont << endl ;
}

int main() {
    IO;
    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

