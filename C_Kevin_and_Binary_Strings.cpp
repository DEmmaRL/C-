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

string xorStrings(const string &a, const string &b) {
    int len_a = a.length();
    int len_b = b.length();
    string result = a;
    for (int i = 0; i < len_b; ++i) {
        result[len_a - len_b + i] = (a[len_a - len_b + i] == b[i] ? '0' : '1');
    }
    return result;
}

void solve() {
    string s; 
    cin >> s;

    string a = s, b;
    string res = a;
    vi ceros;
    fore(i, 0, res.size()) {
        if (res[i] == '0') {
            ceros.pb(i);
        }
    }
    int l1 = 1, r1 = res.size(), l2 = 1, r2 = 1;

    if (!ceros.empty()) {
        b = "1";
        string maxi = xorStrings(a, b);

        fore(i, 0, ceros.size()) {
            int tam = s.size() - ceros[i];
            bool aux = false;
            for (int j = 0; j < s.size(); ++j) {
                if ((j + tam) - 1 < s.size()) {
                    if (s[j] == '1') {
                        aux = true;
                        string currentXor = xorStrings(a, s.substr(j, tam));
                        if (currentXor > maxi) {
                            maxi = currentXor;
                            l2 = j + 1;
                            r2 = j + tam;
                        }
                    }
                } else {
                    break;
                }
            }
            if (aux) break;
        }
    }

    cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl; 
}

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
