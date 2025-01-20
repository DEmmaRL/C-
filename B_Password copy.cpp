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

int alph[ 26 ];

void solve() {
   string s ;
   cin>>s;
    Hash h(s);
   

   unordered_map<lli, lli> mapa ;
   unordered_map<lli, pii > index ;

   vector<pii> v;

   fore(i,0,s.size()){
    lli tmp = h.get(0, i+1) ;
    mapa[ tmp ]++;
    index[ tmp ] = { 0 , i + 1 } ;
   }
   fore(i,0,s.size()){
    lli tmp = h.get(i, s.size()) ;
    mapa[ tmp ]++;
    index[ tmp ] = { i, s.size() } ;
   
   }

   bool res = false ;

   string f = "" ;

   for(auto e : mapa){
    
    if(e.ss == 2 &&  index[e.ff].ss - index[e.ff].ff > f.size() ){
        int l = index[e.ff].ff , r = index[e.ff].ss , tam = (r - l );

        for( int i=1 ; i < s.size() && i + (tam-1) < s.size() - 1; ++i ){

            //cout<<"comparamos en "<<i<<" "<< i + tam-1 << endl;
            //cout<<"hash es "<<h.get( i , i + tam  )<<endl;
            //cout<<"DEBE SER "<<e.ff<<endl;
            if( h.get( i , i + tam  ) == e.ff){
                res = true ;
                if( f.size() < tam ){
                    f = "" ;
                    for(int j=l ; j< r ; ++j ){
                        f+=s[j];
                    }
                }
            }

        }
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
