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
using vi = vector<int>;
using pii = pair<lli, lli>;

void solve() {
    int t ;
    cin >> t ;
    while (t--)
    {
        string a , b; 
        cin>>a>>b ;
        if(a.size() > b.size() ) swap(a,b);
        int res = 0 ;

        int i = 0 ;

        for( i ; i < a.size() ; ++i ){
            if(a[i] != b[i]) break ;
        }
        //cout<<"# "<<i<<endl;
        res = i ;

        if(res) res++;
        //cout<<res<<endl;
        res+= a.size() - (i ); 
        res+= b.size() - (i ); 
        cout<<res<<endl;
    }
    
}

int main() {
    IO;
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
