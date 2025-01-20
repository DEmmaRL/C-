const int MAX_N = 20; 
vector<long long> factorials(MAX_N + 1); 
void precalculateFactorials() { 
    factorials[0] = 1; 
    for (int i = 1; i <= MAX_N; ++i) { 
        factorials[i] = factorials[i - 1] * i; 
        } 
    } 
int main() { 
    int T; 
    cin >> T;
    precalculateFactorials(); 
    while (T--) { 
        int N, K; cin >> N >> K; 
        if (N > K) { cout << 0 << endl; 
        } else { 
            cout << factorials[N] << endl; 
        } 
    } return 0;
}