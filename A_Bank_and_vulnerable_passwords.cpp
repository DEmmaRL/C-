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

struct Node {
    map<char, int> next;
    int end = 0;
};

vector<Node> trie;
bool vulnerable = false;

// Crear nuevo nodo y añadirlo al Trie
int newNode() {
    trie.push_back(Node());
    return sz(trie) - 1;
}

// Añadir palabra al Trie
void add(const string& s) {
    int pt = 0; // Comienza en el nodo raíz
    for (char c : s) {
        if (!trie[pt].next.count(c)) {
            trie[pt].next[c] = newNode();
        }
        pt = trie[pt].next[c];
        if (trie[pt].end) {
            vulnerable = true; 
        }
    }
    trie[pt].end++; // Marca el final de la palabra
}

void search(const string& s) {
    int pt = 0; // Comienza en el nodo raíz
    int i = 0 ;
    for (char c : s) {
        pt = trie[pt].next[c];
        if (trie[pt].end == 1 && i != s.size() - 1 || trie[pt].end > 1 ) {
            vulnerable = true;
            break; 
        }
        i++;
    }
}

void solve() {
    trie.pb(Node()); // Añadir el nodo raíz
    int n;
    cin >> n;
    vector<string> v(n);

    fore(i, 0, n) {
        cin >> v[i];
        add(v[i]);
    }

    fore(i, 0, n) {
        search(v[i]);
    }

    if (vulnerable) {
        cout << "vulnerable" << ENDL;
    } else {
        cout << "non vulnerable" << ENDL;
    }
}

int main() {
    IO;
    solve();
    return 0;
}
