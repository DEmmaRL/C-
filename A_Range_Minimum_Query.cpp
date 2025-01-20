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
using vi = vector<lli>;
using pii = pair<lli, lli>;

const int MAX = 1e9+7;

struct SparseTable {
    vector<vector<lli>> st;
    vector<lli> log;

    SparseTable(const vector<lli>& arr) {
        lli n = arr.size();
        lli K = log2(n) + 1;
        st.assign(n, vector<lli>(K));
        log.assign(n + 1, 0);

        for (lli i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }

        for (lli i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }

        for (lli j = 1; j <= log[n]; j++) {
            for (lli i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    lli query(lli L, lli R) {
        lli j = log[R - L + 1];
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};


void solve(){
    int n  ;
    cin>>n ;
    vi v(n);

    fore(i,0,n){
        cin>>v[i];
    }
    int q ;
    cin>>q ;
    SparseTable sp(v) ;
    while(q--){
        int l, r ;
        cin>>l>>r ;
        cout<<sp.query(l,r)<<endl;
    }
}

 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}