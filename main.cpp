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
 
 void solve(int n)
 {

    int cont = 0 ;
    queue<string>cola;
    cola.push("Sheldon");
    cola.push("Leonard");
    cola.push("Penny");
    cola.push("Rajesh");
    cola.push("Howard");
    while( cont<n )
    {
      if(cont+1== n)
      cout<<cola.front()<<endl;
      cola.push(cola.front());
      cola.push(cola.front());
      
      cola.pop();
      
      cont++;
    }
 }
 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    solve(n);
 
    return 0;
}