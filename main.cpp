#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

void solve() {
    string line;
    lli total_sum = 0;

    while (getline(cin, line)) { // Procesar todas las líneas de entrada
        string pattern = "mul(";
        size_t pos = 0;

        while ((pos = line.find(pattern, pos)) != string::npos) {
            size_t start = pos + pattern.size();
            size_t end = line.find(')', start);

            if (end == string::npos) {
                pos++;
                continue; // No hay cierre de paréntesis, no es válido
            }

            string content = line.substr(start, end - start);
            size_t comma = content.find(',');

            if (comma != string::npos) {
                string x = content.substr(0, comma);
                string y = content.substr(comma + 1);

                // Validar que ambos son números válidos
                if (all_of(x.begin(), x.end(), ::isdigit) && all_of(y.begin(), y.end(), ::isdigit)) {
                    lli a = stoll(x), b = stoll(y);
                    total_sum += a * b;
                }
            }
            pos = end + 1; // Continuar después del cierre del paréntesis
        }
    }

    cout << total_sum << ENDL;
}

int main() {
    IO;
    solve();
    return 0;
}
