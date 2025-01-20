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

const int MAX = 1e9+7;

lli x, y, z ;

lli f(lli a, lli b , lli c) {

    return ( x/a ) * (y / b ) * (z / c ) ;

}

void solve(){

    lli a, b, c, d ;
    cin>>a>>b>>c >>d;
    int i = a ;
    
    int res = 0 ;

    while( i!=b ){

        //cout<<"Pasamos por "<<i<<endl;
        if( i == c || i == d){
            res++;
            //cout<<"llegamos"<<endl;
            break;
        }


        i++;
        if(i==13){
            i=1;
        }

    }

    i = a ;

    while( i!= b ){
        //cout<<"Pasamos por "<<i<<endl;
        if( i == c || i == d){
            //cout<<"llegamos"<<endl;
            res++;
            break;
        }


        i--;
        if(i==0){
            i=12;
        }

    }

    i = b ;

    while( i!= a ){
        //cout<<"Pasamos por "<<i<<endl;
        if( i == c || i == d){
            
            //cout<<"llegamos"<<endl;
            res++;
            break;
        }


        i--;
        if(i==0){
            i=12;
        }

    }

    i = b ;

    while( i!= a ){
        //cout<<"Pasamos por "<<i<<endl;
        if( i == c || i == d){
    
            
            res++;
            break;
        }


        i++;
        if(i==13){
            i=1;
        }

    }

    if(res==4){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }

    return ;
}
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}