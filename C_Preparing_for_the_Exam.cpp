#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;

void solve() {
    int n , m ,k ;
    cin>>n >>m>>k;

    vi a(m);

    fore(i,0,m){
        cin>>a[i];
    }
    unordered_set<int>st;

    fore(i,0,k){
        int tmp;
        cin>>tmp ;
        st.insert(tmp);
    }

    if(n - k >=2){
        fore(i,0,m){
            cout<<"0";
        }
        cout<<endl ;
        return ;
    } 

    vi v ;
    
    fore(i,1,n+1){
        if( st.find(i) == st.end() ){
            v.pb(i);
        }
    }
    string res = "";

    fore(i,0,m){

        if(v.size()==0){
            res+="1";
        }
        
        else if(v.size()==1){

            if( v[0] == a[i] ){
                res+="1";
            } else {
                res+="0";
            }

        } else {

            res+="0";

        }


    }

    cout<<res<<endl;
    
    
    
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
