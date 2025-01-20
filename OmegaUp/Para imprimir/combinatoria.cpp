/*
Este programa resuelve el problema de contar la cantidad de secuencias no decrecientes de longitud n 
donde cada elemento está entre 1 y m (inclusive). La solución se basa en combinaciones matemáticas, 
específicamente en el cálculo de combinaciones con repetición.

El problema se reduce a calcular el coeficiente binomial:
C(n + m - 1, m - 1) % MOD

Donde:
- n es la longitud de la secuencia.
- m es el rango de los valores en la secuencia (de 1 a m).
- MOD es 1e9 + 7 para manejar grandes números y evitar desbordamiento.

El programa incluye funciones para:
1. Cálculo de exponenciación modular.
2. Cálculo de inverso modular utilizando exponenciación rápida.
3. Cálculo del coeficiente binomial modular.

El resultado final se imprime en la salida estándar.
*/

// Function to perform modular exponentiation
lli mod_exp(lli base, lli exp, lli mod) {
    lli result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to compute modular inverse
lli mod_inv(lli x, lli mod) {
    return mod_exp(x, mod - 2, mod);
}

// Function to compute nCr % mod
lli nCr_mod(lli n, lli r, lli mod) {
    if (r > n) return 0;
    lli num = 1, denom = 1;
    for (lli i = 0; i < r; ++i) {
        num = (num * (n - i)) % mod;
        denom = (denom * (i + 1)) % mod;
    }
    return (num * mod_inv(denom, mod)) % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;

    cout << nCr_mod(n + m - 1, m - 1, MOD) << ENDL;
}

int main() {
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}