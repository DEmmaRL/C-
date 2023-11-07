#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<int, int>;

void solve(){
  lli n, q, aux, p = 31;
  cin >> n >> q;

  vi arr(n), qt;
  fore(i,0,n) cin >> arr[i];

  fore(i,0,q){
    cin >> aux;
    if(aux < p){
      qt.pb(aux);
      p = aux;
    }
  }

  fore(i,0,n){
    for (auto x : qt)
      if (arr[i] % (1 << x) == 0)
        arr[i] += 1 << (x-1);
    cout << arr[i] << " ";
  }
  cout << ENDL;
}

int main(){
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}