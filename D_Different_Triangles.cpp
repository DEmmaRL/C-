#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

void solve() {
    lli N;
    cin >> N;
    lli total_count = 0;

    for (lli p = 3; p <= N; p++) {
        // Contamos triángulos no degenerados
        for (lli a = 1; a <= p / 3; a++) {
            for (lli b = a; b <= (p - a) / 2; b++) {
                lli c = p - a - b;
                if (b <= c && a + b > c) {
                    total_count++;
                }
            }
        }
        // Si el perímetro es par, sumamos los triángulos degenerados
        if (p % 2 == 0) {
            total_count += p / 4;
        }
    }

    cout << total_count << ENDL;
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
