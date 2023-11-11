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

    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
    }

    vector<int>ref;

    int k = 1 , it=1 ;
    
    set<int>st;

    while( k <= n )
    {
        ref.pb(k);
        st.insert( k );   
        k*=2;
    }

    bool res = true ;

    for(int i=0; i<n-1; ++i)
    {
        if( v[i]>v[i+1] && st.find(i+1) == st.end() )
        {
            res = false ;
            break;
        }
    }

    
    if(res)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

 }
 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
 
    return 0;
}