#include<bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
//freopen("Round1.in", "r", stdin);
// r = read  || stdin = standard input
//freopen("out", "w", stdout);
// w = write || stdout = standard output
 
using namespace std;
typedef long long lli;
 //g++ other.cpp && a < input.txt > output.txt
 
const lli MOD = 1e9 + 7;


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    lli t;
    cin>>t;
    while(t--)
    {
      lli n, minimo = 1e9;
      cin>>n;
      vector<lli>v(n);
      for(int i=0; i < n ;++i)
      {
        cin>>v[i];
        minimo = min(minimo, v[i]);
      }
      int cont = 0 ;

      for(int i=0; i<n; ++i)
      {
        cont+= v[i]- minimo;
      }
      cout<<cont<<endl;
      

    }
 
    return 0;
}