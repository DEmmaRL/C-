#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD  = 1e9 + 7 ;

void solve(){
    int n ;
    cin>>n;

    set<int>st;

    fore(i,0,n){
        int tmp ; cin>>tmp ;
        st.insert(tmp);
    }

    string a = "Alice" , b = "Bob";

    if( sz(st) == 1 || st.find(1) == st.end()){

        cout<<a<<endl ;

    } else {

        vector<int>v;

        for(auto e : st) {
            v.pb(e);
        }

        int cont = 0 ;

        fore(i, 1 , sz(v)){
            if( v[i] - 1 == v[i-1] ){
                cont++;
            } else break ;
        }
        cont++;

        if(cont== sz(st) ){
            cont--;
            if(cont%2==0){
                cout<<a<<endl; 
            } else {
                cout<<b<<endl;
            }
        }
        //cout<<cont<<endl; 
        else{
            if(cont%2==0){
                cout<<a<<endl; 
            } else {
                cout<<b<<endl;
            }
        }

    }
}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}