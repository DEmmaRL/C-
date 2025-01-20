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

void solve() {
    string s;
    cin >> s;

    lli sum = 0;
    int dos = 0, tres = 0;

    fore(i, 0, s.size()) {
        int tmp = s[i] - '0';
        sum += tmp;
        if (tmp == 2) dos++;
        if (tmp == 3) tres++;
    }

    // Si ya es divisible por 9
    if (sum % 9 == 0) {
        cout << "YES" << ENDL;
        return;
    }

    unordered_set<lli> visited; 
    queue<pair<lli, pair<int,int> > > cola; 

    cola.push( { sum , {dos, tres} } );
    visited.insert(sum);

    while (!cola.empty()) {
        auto frente = cola.front();
        cola.pop();
        //cout<<frente.ff<<endl;    

        if(frente.ss.ss >= 1){
            lli nSum = frente.ff + 6 ;

            if( visited.find(nSum) == visited.end() ){
                visited.insert(nSum) ;
                cola.push({ nSum , {frente.ss.ff , frente.ss.ss-1}});
                if(nSum % 9 == 0){
                    cout<<"YES"<<endl;
                    return ;
                }
            }
        }
        if(frente.ss.ff >= 1){
            lli nSum = frente.ff + 2 ;

            if( visited.find(nSum) == visited.end() ){
                visited.insert(nSum) ;
                cola.push({ nSum , {frente.ss.ff-1 , frente.ss.ss}});
                if(nSum % 9 == 0){
                    cout<<"YES"<<endl;
                    return ;
                }
            }
        }



    }

    cout << "NO" << ENDL;
}

int main() {
    IO;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
