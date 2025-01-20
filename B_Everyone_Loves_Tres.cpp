#include <bits/stdc++.h>
#define ENDL '\n'
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1 || n == 3) {
        cout << -1 << ENDL;
    } else if (n % 2 == 0) {
        // For even n, construct n-2 '3's followed by "66"
        cout << string(n - 2, '3') << "66" << ENDL;
    } else {
        // For odd n >= 5, construct n-5 '3's followed by "36366"
        cout << string(n - 5, '3') << "36366" << ENDL;
    }
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
