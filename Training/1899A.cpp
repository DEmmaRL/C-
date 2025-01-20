#include<bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
//freopen("Round1.in", "r", stdin);
// r = read  || stdin = standard input
//freopen("out", "w", stdout);
// w = write || stdout = standard output
 
using namespace std;
typedef unsigned long long int lli;
 //g++ main.cpp && a < input.txt > output.txt

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        if( n % 3 == 0 )
        {
            cout<<"Second"<<endl;
        }
        else
        {
            cout<<"First"<<endl;
        }   

    }
    

    return 0;
}