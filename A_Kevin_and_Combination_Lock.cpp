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
using pii = pair<lli, lli>;

bool canUnlock(lli x) {
    if (x == 0) return true;
    while (x >= 33) {
        if (x % 33 == 0) return true;
        string s = to_string(x);
        size_t pos = s.find("33");
        if (pos != string::npos) {
            s.erase(pos, 2);
            x = stoll(s);
        } else {
            x -= 33;
        }
    }
    return x == 0;
}

void solve() {
    lli t;
    cin >> t;
    while (t--) {
        lli x;
        cin >> x;
        cout << (canUnlock(x) ? "YES" : "NO") << ENDL;
    }
}

int main() {
    IO;
    solve();
    return 0;
}
