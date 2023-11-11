#include<bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
//freopen("Round1.in", "r", stdin);
// r = read  || stdin = standard input
//freopen("out", "w", stdout);
// w = write || stdout = standard output
 
using namespace std;
typedef long long lli;
 //g++ main.cpp && a < input.txt > output.txt

 void solve()
 {

    int n;
    cin>>n;
    vector<int>v(n);
    
    int res = 0, total = 0   ;  
    
    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
        total+=v[i];
    }

    for(int i=0; i<n; ++i)
    {
        
        for(int j = 0 ; j<n; ++j)
        {
            int unos = 0 ;
            for(int k=0; k< n ; ++k)
            {
                if(k >= i && k <=i + j ) 
                {
                    v[k]=1 - v[k];
                }
                if(v[k])
                {
                    unos++;
                }
                if(k >= i && k <=i + j )
                {
                    v[k]=1 - v[k];
                }

            }

            res = max (res ,unos );

        }

        
    }
    cout<<res<<endl;


    return;
 }
 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
 
    return 0;
}