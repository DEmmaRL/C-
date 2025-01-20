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

vector<vector<char> > rotate( vector<vector<char> > matrix) {
    int n = matrix.size();
    
    // Transposición de la matriz
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Invertir cada fila
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix ;
}

void solve() {
    int n ;
    cin>>n;

    vector<vector<char> > matrix(n) , m1 , m2, m3;

    fore(i,0,n){
        fore(j,0,n){
            char tmp ;
            cin>>tmp;

            matrix[i].pb(tmp);
        }
    }

    m1 = rotate(matrix) ;

    m2 = rotate(m1) ;

    m3 = rotate(m2) ;

    lli res = 0 ;

    fore(i,0,n){
        fore(j,0,n){
            char tmp = max( matrix[i][j] , max(m1[i][j] , max(m2[i][j], m3[i][j] ) ) ) ;
            //cout<<tmp <<endl ;
            res += tmp - matrix[i][j];
            res += tmp - m1[i][j];
            res += tmp - m2[i][j];
            res += tmp - m3[i][j];
        }
    }
    //cout<<endl ;
    cout<<res/4<<endl;

}

int main() {
    IO;
    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
