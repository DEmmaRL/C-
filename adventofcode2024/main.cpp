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

bool f(int x, vi &v){

    bool a = true ;

    fore(i,0, v.size() - 1 ){
        if( x == i ){
            continue;
        } 
        int other = v[i+1];
        if(x==i+1){
            if( i+2 >= v.size() ){
                break ;
            } else {
                other = v[i+2];
            }
        }
        if( other <= v[i] || abs(other-v[i]) > 3 ){
            a = false ;
            break;
        }
    }
    if(a){
        return true ;
    } else {
        a = true ;

        fore(i,0, v.size() - 1 ){
            if( x == i ){
                continue;
            } 
            int other = v[i+1];
            if(x==i+1){
                if( i+2 >= v.size() ){
                    break ;
                } else {
                    other = v[i+2];
                }
            }
            
            if( other >= v[i] || abs(other-v[i]) > 3 ){
                a = false ;
                break;
            }
        }
        if(a){
            return true ;
        }   
    }
    return false ;

}

void solve() {
    string s;
    int res = 0 ; 
    while( getline(cin,s) ){
        

        string tmp = "" ;

        vi v;

        fore(i,0, s.size()){

            if( s[i]==' ' && tmp != "" ){
                v.pb(stoi(tmp));
                tmp = "" ;
            } else if( s[i] != ' ') {
                tmp+=s[i];
            }

        }

        if(tmp!="") v.pb(stoi(tmp));

        bool a = true ;

        fore(i,0, v.size() - 1 ){
            if( v[i+1] <= v[i] || abs(v[i+1]-v[i]) > 3 ){
                a = false ;
                break;
            }
        }
        if(a){
            res++;
        } else {
            a = true ;

            fore(i,0, v.size() - 1 ){
                if( v[i+1] >= v[i] || abs(v[i+1]-v[i]) > 3 ){
                    a = false ;
                    break;
                }
            }
            if(a){
                res++;
            }   
        }

        if(a){
            fore(i,0,v.size()){
           //     cout<<v[i]<<" ";
            }
           // cout<<endl;
        } else {

            bool c = false;

            fore(i,0,v.size()){
                if(f(i,v)){
                    c = true ;
                    res++;
                    break ;
                }
            }

        }

    }
    cout<<res<<endl;
}
 

int main() {
    IO;
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}