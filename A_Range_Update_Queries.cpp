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

struct LazySegtree{
    #define mid (l+r) / 2
    #define left(u) (u+1)
    #define right(u) (u + ((mid - l + 1) <<1))

    struct Node
    {
        lli s, lazy;
        Node(lli s = 0 , lli lazy = 0): s(s) , lazy(lazy){}

        Node operator + (const Node &n){
            return Node(s + n.s);
        }
    };
    vector<Node> st ;
    
    LazySegtree(int n): st(2*n){}

    void push(int u, int l, int r){
        if(st[u].lazy){
            if(l<r){
                st[left(u)].lazy += st[u].lazy;
                st[right(u)].lazy += st[u].lazy;                
            }
            st[u].s += st[u].lazy * (r - l + 1);
            st[u].lazy = 0 ;
        }
    }

    void update(int u, int l, int r, int ll, int rr, lli val){
        push(u,l,r);
        if( l > r or r < ll or l > rr ) return ;
        if( ll <= l and r <= rr){
            st[u].lazy += val;
            push(u,l,r);
            return ;
        }

        update(left(u), l,mid,ll,rr,val);
        update(right(u), mid+1,r,ll,rr,val);
        st[u] = st[left(u)] + st[right(u)];
    }

    Node query( int u, int l, int r , int ll, int rr ){
        push(u,l,r);
        if(l > r or r < ll or l > rr) return Node();
        if(ll <= l and r <= rr) return st[u];
        return query(left(u), l , mid, ll, rr) + query(right(u), mid+1, r, ll, rr ) ;
    }
    
};

void solve() {
    lli n, q;
    cin>>n>>q;

    vi v(n);

    LazySegtree segtree(n);
    // segtree.update(0, 0, n - 1, ll, rr, val);

    fore(i,0,n){
        cin>>v[i];
        segtree.update( 0 , 0, n - 1 , i, i, v[i]);
    }

    while(q--){
        lli act ;
        cin>>act;
        if(act == 1) {
            lli a, b, u;
            cin>>a>>b>>u;
            --a, --b;
            segtree.update(0,0,n-1, a, b, u);

        } else {
            lli k;
            cin>>k;
            --k;
            cout<<segtree.query(0,0,n-1, k, k).s<<endl;
        }
    }
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
