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
  int n ;
  cin>> n ;
  vi v(n);
  fore(i,0,n){
    cin>>v[i];
  }
  sort(all(v));
  cout<<abs(v[0] - v[n-1])<<endl;
}

int main(){
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}