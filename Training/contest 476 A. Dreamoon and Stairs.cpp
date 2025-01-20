#include<bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define f first
#define s second
#define fore(i,a,b) for(int i=(a), ThxMK = (b); i < ThxMK; ++i)
#define sz(s) int(s.size())
//freopen("Round1.in", "r", stdin);
// r = read  || stdin = standard input
//freopen("out", "w", stdout);
// w = write || stdout = standard output

typedef long long ll;
using namespace std;
 //g++ main.cpp && a < input.txt > output.txt
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n , k ;
    
    cin>>n>>k;

    int cont = ( n / 2 ) + ( n%2 ) ;

    while( cont <= n && cont%k != 0 )
    {
        cont++;
    }

    if(cont%k==0 && cont<=n)
    {
        cout<<cont<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    



    return 0;
}