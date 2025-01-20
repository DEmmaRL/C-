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
 
struct LazySegtree {
    #define mid (l + r) / 2
    #define left(u) (u + 1)
    #define right(u) (u + ((mid - l + 1) << 1))
 
    struct Node {
        int l, r, lazy;
        Node(int a = 0, int b = 0, int lazy = 0): l(a), r(b), lazy(lazy) {}
 
        Node operator + (const Node &n) {
            int izq = max(0, l - n.r) + n.l;
            int der = max(0, n.r - l) + r;
            return Node(izq, der, 0);
        }
    };
 
    vector<Node> st;
 
    LazySegtree(int n): st(2 * n) {}
 
    void push(int u, int l, int r) {
        if (st[u].lazy) {
            if (l < r) {
                st[left(u)].lazy += st[u].lazy;
                st[right(u)].lazy += st[u].lazy;
            }
            st[u].l += st[u].lazy * (r - l + 1);
            st[u].lazy = 0;
        }
    }
 
    void update(int u, int l, int r, int pos, int val) {
        push(u, l, r);
        if (l == r) {
            if( val == 1 )
                st[u].l = 1 ;
            else 
                st[u].l = 0 ;
            
            if( val == -1 )
                st[u].r = 1 ;
            else 
                st[u].r = 0 ;
            
            return;
        }
        if (pos <= mid) update(left(u), l, mid, pos, val);
        else update(right(u), mid + 1, r, pos, val);
        st[u] = st[left(u)] + st[right(u)];
    }
 
    Node query(int u, int l, int r, int ll, int rr) {
        push(u, l, r);
        if (l > r || r < ll || l > rr) return Node();
        if (ll <= l && r <= rr) return st[u];
        return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
    }
};
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
 
    LazySegtree segtree(n);
    fore(i, 0, n) {
        if (s[i] == '(') {
            segtree.update(0, 0, n - 1, i, 1);
        } else {
            segtree.update(0, 0, n - 1, i, -1);
        }
    }
 
    while (q--) {
        int k;
        cin >> k;
        if (k == 0) {
            auto result = segtree.query(0, 0, n - 1, 0, n - 1);
            if (result.l == 0 && result.r == 0) {
                cout << "YES" << ENDL;
            } else {
                cout << "NO" << ENDL;
            }
        } 
        else {
            k--; 
            if ( s[k] == '(' ) {
                segtree.update(0, 0, n - 1, k, -1);
                s[k] = ')' ;
            
            } 
            else {
                segtree.update(0, 0, n - 1, k, 1);
                s[k] = '(' ;
            }
        }
    }
}
 
int main() {
    IO;
    int t = 10;
    //cin >> t;
    fore(i,1, t+1) {
        cout<<"Test "<<i<<":"<<endl;
        solve();
    }
    return 0;
}
 