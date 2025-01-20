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

void solve() {
   string a, b ;
   cin>>a>>b ;

   int cont = 0 , uno = 0 , cero = 0 ;

   fore(i,0, a.size()){
    if(a[i]=='0') cero++; else uno++;
   }

   vi v , arr;

   for(int i = 1 ; i * cero <= b.size() ; ++i ){

    if( (b.size() - (i*cero) ) % uno == 0 ){
        v.pb(i) ;
    }

   }
    /*
   int cantUnos = 0 ;
   bool tmpceros = true ;

   fore(i,0, a.size()){
    if( a[i]== '0' ){
        if(tmpceros && cantUnos == 0 ){
            tmpceros = false ;
        } else {
            break;
        }
    }else{
        cantUnos++;
    }
   }
    */
   for(int i = 1 ; i * uno <= b.size() ; ++i ){

    if( (b.size() - (i*uno) ) % cero == 0 ){
        arr.pb(i) ;
    }

   }


    Hash h(b);

    fore(i,0,v.size()){
        fore(j,0,arr.size()){
            if( ( v[i] * cero ) + ( arr[j] * uno ) == b.size() ){

                int iter = 0 ;
                lli huno = -1 , hcero = -1 ;
                bool check = true ;
                fore(k,0,a.size()){
                    if( a[k]=='0' ){
                        if( hcero == -1 ){
                            hcero = h.get(iter, iter + v[i] );
                        } else {
                            lli cur = h.get(iter, iter + v[i] );
                            if(cur != hcero){
                                check = false ;
                                break;
                            }
                        }
                        iter+= v[i];
                    } else {
                        if( huno == -1 ){
                            huno = h.get(iter, iter + arr[j] );
                        } else {
                            lli cur = h.get(iter, iter + arr[j] );
                            if(cur != huno){
                                check = false ;
                                break;
                            }
                        }
                        iter+= arr[j];
                    }
                    if(hcero == huno){
                        check = false ;
                        break ;
                    }
                }

                if(check){

                  //  cout<<"se puede con cero = "<< v[i] << " y uno = " << arr[j] <<endl; 
                    cont++;
                }

            }
        }
    }

    cout<<cont<<endl;


}

int main() {
    IO;
        solve();
    

    return 0;
}
