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
    lli n, cont = 0 ;
    cin>>n;
    vector<lli>v(n);

    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
        
    }
    
    sort( v.begin() , v.end() ) ;

    deque<int> cola(v.begin(), v.end());
    lli x = 0 ;
    while(!cola.empty())
    {
        if( cola.size()==1 )
        {
            lli tempo = cola.front();
            if(x)
            {
                cont++;
                tempo-=x;
            }    
                cont+= (tempo / 2 )   + 1  ; 

                break;

            
        }
        lli tmp = cola.front();
        cola.pop_front();

        x+=tmp;

        if( x > cola.back() )
        {
            //la operación del mayor
            cont++;
            //la operacion del menor
            cont+=tmp - ( tmp - ( x - cola.back() ) ) ;
            
            cola.push_front( tmp - ( x - cola.back() ) );
            
            cola.pop_back();
        }
        else if(x == cola.back())
        {
            //la operación del menor y la del mayor
            cont+=1 + tmp;
            cola.pop_back();
            x = 0 ;
        }
        else
        {
            //la operación del menor
            cont+=tmp;
        }
    }
    cout<<cont<<endl;

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