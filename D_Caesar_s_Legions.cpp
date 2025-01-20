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

const int MAXN = 107 , MAXK = 11 , MOD = 1e8;

int dp[ MAXN ][ MAXN ][ MAXK ][ MAXK ] ;

int a, b ;

int fun( int n1, int n2, int k1 = 0 , int k2 = 0 ){

    if(n1== 0 && n2 == 0) return 1 ;
    int tmp = 0 ;
    if(n1 && k1 +1 <= a){
       // cout<<"d"<<endl;

       if(dp[n1-1][n2][k1+1][0] == -1) {
            dp[n1-1][n2][k1+1][0] = fun(n1-1, n2, k1+1, 0);
        }

        tmp = ( tmp + dp[n1-1][n2][k1+1][0] ) % MOD ;
    }
    if(n2 && k2 +1 <= b){
       // cout<<"a"<<endl;
        if( dp[n1][n2-1][0][k2+1] == -1 ){
            dp[n1][n2-1][0][k2+1] = fun( n1 , n2-1, 0 , k2+1 ) ; 
        }
        tmp = ( tmp + dp[n1][n2-1][0][k2+1] ) % MOD ;
    }
    dp[n1][n2][k1][k2] = tmp ;
    return tmp ;
}


void solve() {
   memset(dp, -1, sizeof(dp));
    int n1 , n2;
    cin>>n1>>n2>>a>>b;
    cout<<fun(n1,n2)<<endl;
}

int main() {
    IO;
        solve();
    

    return 0;
}
