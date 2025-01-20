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

lli k ;

struct Node {
    lli s, tam;
    vi arr;
    bool okay ;
    Node(lli s = 0, vi arr = vi(6, 0), lli tam = 0, bool okay = true ) 
        : s(s), arr(arr), tam(tam) {}

    Node operator + (const Node &n) {
        vi arrTmp(6, 0);
        fore(i, 0, 6) {
            arrTmp[i] = arr[i] + n.arr[i];
        }
        bool tmpRes = true ;
        if( tam + n.tam > k ) tmpRes = false ;

        return Node(s + n.s, arrTmp, tam + n.tam, tmpRes);
    }
};

struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  
  void update(int u, int l, int r, int kth, Node val){ 
    if(l == r){
      st[u] = val;
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  
  Node query(int u, int l, int r, int ll, int rr){ 
    if (ll > r || rr < l) return Node();
    if (ll <= l && r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }

  Node querie(int u, int l, int r, int ll, int rr){ 
    if (ll > r || rr < l) return Node();
    if (ll <= l && r <= rr) return st[u];
    Node a = querie(left(u), l, mid, ll, rr) ;
    Node b = querie(right(u), mid + 1, r, ll, rr);
    


    return res ;
    
  }
};

void solve() {
    int n, m;
    cin >> n >> m >> k;

    Segtree st(n);

    fore(i, 0, n){
        vi arr(6, 0);
        lli tam = 1, s = 0;

        fore(j, 0, m) {
            cin >> arr[j];
            s += arr[j];
        }
        st.update(1, 0, n - 1, i, Node(s, arr, 1));
    }
    fore(i,0,m){
        cout<<st.querie(1,0,n-1, 0, n-1).arr[i]<<" ";
    }
    cout<<endl;

}

int main() {
    IO;
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
