#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(lli i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

struct Hash {
    int P=1777771,MOD[2],PI[2];
    vector<int> h[2],pi[2];
    Hash(string& s){
        MOD[0]=999727999;MOD[1]=1070777777;
        PI[0]=325255434;PI[1]=10018302;
        for(int k = 0; k < 2; ++k)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
        for(int k = 0; k < 2; ++k){
            h[k][0]=0;pi[k][0]=1;
            long long p=1;
            for(int i = 1; i < (int)(s.size()) + 1; ++i){
                h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
                pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
                p=(p*P)%MOD[k];
            }
        }
    }
    long long get(int s, int e){
        long long h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
        h0=(1LL*h0*pi[0][s])%MOD[0];
        long long h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
        h1=(1LL*h1*pi[1][s])%MOD[1];
        return (h0<<32)|h1;
    }
};

string s ;

bool check( Hash &h , lli k , int tam ){
    //cout<<"we search for "<<k<<" de "<< tam<<endl;
    
    for(int i = 1 ; i + tam < s.size() ; ++i ){
        if( h.get(i , i + tam ) == k )
            return true ;
    }

    return false ;
}

int alph[ 26 ];

void solve() {
   
   cin>>s;
    Hash h(s);
   

   

   vector<pii> v;
   
   int iter = s.size()-1 ;
   
   fore(i,0,s.size()){
    lli a = h.get(0, i+1) , b = h.get( iter, s.size()) ;
    if( a == b ){
        v.pb({0, i });
       
    }
    iter--;
   }

   bool res = false ;

   string f = "" ;

    if( v.size() ){
        int l = 0 , r = v.size()-1 ;

        while( r - l > 2 ){
            int mid = ( l + r ) / 2 ;

            if( check( h, h.get( v[mid].ff , v[mid].ss + 1 ) , 
                ( v[mid].ss - v[mid].ff ) + 1 ) ){
                  l = mid ;
            } else {
                r = mid - 1 ;
            }
        }

        pii tmp ;

        for(int i = l ; i <= r && r < s.size(); ++i ){
            if(check( h , h.get( v[i].ff , v[i].ss + 1 ) , 
                ( v[i].ss - v[i].ff ) + 1 ) ){
                res = true ;
                tmp = v[i];
            }
        }

        for(int i=tmp.ff ; i <= tmp.ss ; ++i){
            f+=s[i];
        }

    }

    if(res){
        cout<<f<<endl;
    } else {
        cout<<"Just a legend"<<endl;
    }

}

int main() {
    IO;
        solve();
    

    return 0;
}
