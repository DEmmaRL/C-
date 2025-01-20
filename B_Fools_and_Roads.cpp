#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define f first
#define s second
#define fore(i,a,b) for(lli i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

const int MAX = 1e5 + 7 ;

// Variables globales para el recorrido de Euler
vector<lli> eulerTour; // Almacena el orden de los nodos en el recorrido
vector<lli> firstOccurrence; // Almacena la primera aparición de cada nodo
vector<lli> graph[MAX];
// DFS para generar el Euler Tour
void initEulerTour(lli node, lli parent) {
    eulerTour.pb(node); // Añade el nodo al recorrido
    firstOccurrence[node] = eulerTour.size() - 1;

    for (auto neighbor : graph[node]) {
        if (neighbor != parent) {
            initEulerTour(neighbor, node);
            eulerTour.pb(node); // Añadir de nuevo el nodo después de regresar
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    lli n, u, v;
    cin >> n; // Número de nodos

    // Inicializar el grafo y las estructuras
    firstOccurrence.assign(n + 1, -1);
    eulerTour.clear();

    // Leer las aristas del grafo
    fore(i, 1, n) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    // Realizar DFS desde el nodo 1 (se asume nodo raíz 1)
    initEulerTour(1, -1);

    // Mostrar el Euler Tour
    cout << "Euler Tour: ";
    for (auto node : eulerTour) {
        cout << node << " ";
    }
    cout << ENDL;

    return 0;
}
