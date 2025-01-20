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
using vi = vector<lli> ;
#define INF 1e17 

vi kmppre(string& t){ // r[i]: longest border of t[0,i)
    vi r(t.size() + 1 ); r[0] = -1 ;
    int j = -1 ;
    fore(i,0,t.size()){
        while(j>=0&&t[i]!=t[j])j=r[j];
        r[i+1]=++j;
    }
    return r;
}
int kmp(string& s, string& t){
    int res = 0 ;
    int j=0; vi b=kmppre(t);
    vi v;
    fore(i,0,s.size()){
        while(j>=0&&s[i]!=t[j])j=b[j];
        if(++j==(int)t.size())
        v.pb(i-j+1),j=b[j];
    }
    sort(all(v));
    if(v.size()){
        res = 1 ;
        int d = t.size() - 1;
        fore(i,1,v.size()){
            if( d < v[i] ){
                res++;
                d = ( v[i] + t.size() ) - 1 ;
            }
        }   
    } 
    return res ;
}

void solve() {
    
    string a, b ;
    cin>>a>>b;
    cout<<kmp(a,b)<<endl;

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