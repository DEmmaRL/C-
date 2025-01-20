#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool check( vi v , int skip ){

    fore( i , 1 , sz(v) - 1 ){

    if(i == skip) continue ;

    int a = i + 1 , b = i - 1 ;

    if(a == skip) {
        a++;

        if( a >= sz(v) ){
            break;
        }
    }
    if(b == skip){
        b--;

        if(b < 0 )
        continue;
    }

    if( gcd(v[i], v[a]) < gcd(v[b], v[i]) ){

        return false ;

    }

   }

   return true ;

}

void solve(){

   int n;
   cin>>n;

   vi v(n);

   fore(i,0,n){
    cin>>v[i];
   }

   int res = -1 ;

    /*
    fore( i , 0 , n - 1 ){

   cout<<gcd(v[i] , v[i+1])<<endl;

   }
    */

   fore( i , 1 , n - 1 ){

    if( gcd(v[i], v[i+1]) < gcd(v[i-1], v[i]) ){

        //cout<<"el gcd de "<<v[i]<<" con "<<v[i+1]<<" es "<<gcd(v[i], v[i+1])<<endl;
        //cout<< "y es menor que el gcd de "<<v[i-1]<<" con "<< v[i]<<" que es "<< gcd(v[i-1], v[i])<<endl;

        if( res == -1 && ( check( v , i ) || check( v , i + 1 ) ) ){

            res = 1 ;
            break;

        } else{
            res = 0 ;
            break;
        }

    }

   }

   if(res == 0 ){

    res = -1 ;

   fore( i , 1 , n - 1 ){

    if( gcd(v[i], v[i+1]) < gcd(v[i-1], v[i]) ){
        if( res == -1 && ( check( v , i ) || check( v , i - 1 ) ) ){

            res = 1 ;
            break;
        } else{
            res = 0 ;
            break;
        }

    }

   }

    if(res == 0 ) cout<<"NO"<<endl;
   
    else cout<<"YES"<<endl;
   } else{
    cout<<"YES"<<endl;
   }

   

}
 
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}