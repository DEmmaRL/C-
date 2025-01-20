
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
using pii = pair<int, int>;

struct Node {
    map<char, int> next;
    bool end = false;
    int prefixCount = 0; // Se añade para contar prefijos
};

vector<Node> trie;
int currNode = 0;

// Crear nodo 0 antes de usar
int newNode() {
    trie.pb(Node());
    return currNode++;
}

bool res = true ;

// Añadir una palabra al trie
void add(string& s) {
    int pt = 0;
    fore(i, 0, sz(s)) {
        if (trie[pt].end) {
            res = false;
        }
        if (!trie[pt].next.count(s[i]))
            trie[pt].next[s[i]] = newNode();
        pt = trie[pt].next[s[i]];
        trie[pt].prefixCount++;
    }
    if (trie[pt].end || sz(trie[pt].next) > 0) {
        res = false;
    }
    trie[pt].end = true;
}

// Eliminar una palabra del trie
void remove(string& s) {
    int pt = 0;
    fore(i, 0, sz(s)) {
        if (!trie[pt].next.count(s[i]))
            return;
        pt = trie[pt].next[s[i]];
    }
    trie[pt].end = false;
}

// Buscar una palabra en el trie
bool find(string& s) {
    int pt = 0;
    fore(i, 0, sz(s)) {
        if (!trie[pt].next.count(s[i]))
            return false;
        pt = trie[pt].next[s[i]];
    }
    return trie[pt].end;
}

// Contar prefijos en el trie
int countPrefixes(string& s) {
    int pt = 0;
    fore(i, 0, sz(s)) {
        if (!trie[pt].next.count(s[i]))
            return 0;
        pt = trie[pt].next[s[i]];
    }
    return trie[pt].prefixCount;
}

// Recorrer el trie usando DFS
void dfs(int pt = 0, string s = "") {
    if (trie[pt].end)
        cout << s << ENDL;

    for (auto& i : trie[pt].next) {
        s.pb(i.ff);
        dfs(i.ss, s);
        s.pop_back();
    }
}

void solve(){
    lli n, m ;
    lli res = 0 ;

    cin>>n>>m;
    m/=2;
    cout<<m * n <<endl;
}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}