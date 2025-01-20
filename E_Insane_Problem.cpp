#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

void solve() {
    lli k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    lli count = 0;
    lli p = 1;

    while (p <= r2) {
        lli x_min = max(l1, (l2) / p);
        lli x_max = min(r1, r2 / p);

        if (x_min <= x_max) {
            count+=x_max - x_min + 1;
        }

        if(p > r2 / k) 
            break;
        p*=k;
    }

    cout << count << ENDL;
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
