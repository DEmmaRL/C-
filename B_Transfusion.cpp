#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(lli i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

bool check(vi &v){
    
    int n = v.size() ;

    lli p = 0 , odd = 0 , even = 0 , a = 0 , b = 0 ;

    fore(i,0,n){
        p+=v[i];
        if(i%2==0){
            odd++;
            a+=v[i];
        } else {
            even++;
            b+=v[i];
        }
    }

    if(p%n!= 0){
        return false ;
    }

    if(a % odd != 0 || b % even != 0 ){
        return false ;
    } 

    if(a / odd != p / n || b / even != p / n ){
        return false ;
    } 

    return true ;
    

}

void solve() {
    
    int n ;
    cin>>n ;

    vi v(n);

    fore(i,0,n){
        cin>>v[i];
    }

    if(check(v)){
        cout<<"YES"<<endl ;
    } else {
        cout<<"NO"<<endl ;
    }

}

int main() {
    IO;
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}
