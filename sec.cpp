#include <iostream>
using namespace std;
 

void KMP(string text, string pattern){// Función para implementar el algoritmo KMP
    int m = text.length();
    int n = pattern.length();    
    if (n == 0){ // si el patrón es una string vacía
        cout << "The pattern occurs with shift 0";
        return;
    }
    if (m < n){ // si la longitud del texto es menor que la del patrón
        cout << "Pattern not found";
        return;
    }
    int next[n + 1]; // next[i] almacena el índice de la siguiente mejor coincidencia parcial
    
    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < n; i++){
        int j = next[i];
        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j];
        }
        if (j > 0 || pattern[j] == pattern[i]) {
            next[i + 1] = j + 1;
        }
    }

    for (int i = 0, j = 0; i < m; i++){
        if (text[i] == pattern[j]){
            if (++j == n) {
                cout << "The pattern occurs with shift " << i - j + 1 << endl;
            }
        }
        else if (j > 0){
            j = next[j];
            i--;    // ya que `i` se incrementará en la siguiente iteración
        }
    }
}
 
// Programa para implementar el algoritmo KMP en C++
int main()
{
    string text = "ABCABAABCABAC";
    string pattern = "CAB";
 
    KMP(text, pattern);
 
    return 0;
}
