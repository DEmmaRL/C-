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

const lli MAX = 1e6 + 7 ;

bool dp[ MAX ] ;



void r(lli carrie, lli curr, lli total)
{
    lli extra = curr + carrie;
    lli new_carrie = extra * curr ; 
    
    lli new_total = total + new_carrie + extra ;

    if(  new_total < MAX &&
        !dp[ new_total]  )
    {
        dp[ new_total] = true ;


        for(lli i=curr; i==curr ; ++i)
        {
            lli extra_2 = i + new_carrie ;
            lli carrie_2 = extra_2 * i ;    
            lli t = new_total + extra_2 + carrie_2 ;

            if( t < MAX )
            {
                if(!dp[ t ])
                {
                    r(new_carrie,  i , new_total );
                }
            }
            else
            {
                break;
            }
        }

    }
    else
    {
        return;
    }

}

void f()
{

    for(lli i=2; i < MAX ; ++i)
    {
            r(0 , i , 1 );
    }

}
 void solve()
 {

    lli n;
    cin>>n;
    if(dp[n])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return;
 }
 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    f();
    lli t;cin>>t;while(t--)
    solve();
 
    return 0;
}