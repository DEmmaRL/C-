#include<bits/stdc++.h>
#define ENDL '\n'

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int lli;
#define pb push_back 
#define f first
#define s second 
#define sz(s) int( s.size() ) 
 //g++ main.cpp && a < input.txt > output.txt

vector<lli> getCoprimes( lli n ){
    vector<bool>isCoprime(n,true);
    vector<lli> coprimes, factProp;
    lli tmp = n , cont = 2 ; 

    while( tmp != 1 && cont <= n ){
        if( tmp % cont == 0 ){
            factProp.pb(cont);
            while(tmp%cont==0) tmp/=cont;
        }
        cont++;
    }

    for(auto e : factProp) {
        isCoprime[e] = false ; 
        for(int j= e ; j < n ; j+=e ) 
            isCoprime[j] = false ;
    }   
    factProp.pb(1); // No olvidemos que el 1 es parte de los coprimos
    for( int i=1 ; i < n ; ++i ){
        if( isCoprime[i] ) coprimes.pb(i); 
    } 
    return coprimes;
}


int main(){
  _

  lli n; 

  cin>>n;

  vector<lli> coprimes = getCoprimes(n);
  
  lli res = 1 ;

  for(int i=0; i < sz(coprimes) ; ++i){
    
    res = (res * coprimes[i]) % n ;
  }
  
  if( res != 1 ){

    cout<<sz(coprimes) - 1 << endl ;

    for( auto e : coprimes ){
        if(e!= res) cout<<e<<" ";
    }
    cout<<endl;
  } else{
    cout<<sz(coprimes) << endl ;

    for( auto e : coprimes ){
        cout<<e<<" ";
    }
    cout<<endl;
  }



   return 0;
}