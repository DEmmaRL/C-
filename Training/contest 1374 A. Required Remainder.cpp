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

    int t;
    cin>>t;
    while(t--)
    {
        ll x, y, n;
        cin>>x>>y>>n;

        ll res = n / x ;

        if( (res * x  ) + y > n )
        {
            res--;
        }
        res *= x ;

        res+=y;

        cout<<res<<endl;
        

    }

    return 0;
}