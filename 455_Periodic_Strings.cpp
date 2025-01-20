#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(x) (int)size(x)

using namespace std;
using pii = pair<double, double>;
using vi = vector<lli> ;

vi kmppre(string& t){
    vi r(t.size() + 1);
    r[0] = -1 ; int j = -1 ;
    fore(i,0,t.size()){
        while(j>= 0 && t[i] != t[j])
           {
j = r[j];
        r[i+1] = ++j;
           } 
    }
    return r; 
}
int kmp(string& s, string& t){
    int j = 0 , cnt = 0; vi b = kmppre(t);
    fore(i,0,s.size()){
        while(j >= 0 && s[i] != t[j])
            j = b[j];
        if(++j == t.size())
            cnt++,
        j = b[j];
    }
    return cnt;
}

void solve() {
    
    string s ;
    cin>>s;

    vi div ;

    for(int i = 1 ; i * i <= s.size() ; ++i ){
        if(s.size()%i == 0 ){
            div.pb(i);
            if( s.size() / i != i ){
                div.pb( s.size() / i );
            }
        }
    }
    sort(all(div));
    
    int res = s.size() ;

    for(auto e : div){
        
        string tmp = "" ;

        fore(i,0,e){
            tmp+=s[i];
        }

        if( kmp(s, tmp) == s.size() / e ){
            res = e ;
            break ;
        }
    }
    cout<<res<<endl ;
    
}

int main() {
    IO;
    int t = 1;
    cin >> t;
    fore(i,0,t){
        solve();
        if(i+1 < t)
        {
            cout<<endl ;
        }
    }
    return 0;
}