#include<bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define f first
#define s second
#define fore(i,a,b) for(int i=(a), ThxMK = (b); i < ThxMK; ++i)
#define sz(s) int(s.size())
//freopen("Round1.in", "r", stdin);
// r = read  || stdin = standard input
//freopen("out", "w", stdout);
// w = write || stdout = standard output

typedef long long ll;

using namespace std;
 //g++ main.cpp && a < input.txt > output.txt

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


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string t, a, b;
    cin>>t>>a>>b;
    vector<pair<int ,int > >ini, fin ; 


    auto hashing = Hash(t);

    auto h1 = Hash(a);
    auto h2 = Hash(b);

    for(int i=0; i<t.size(); ++i)
    {
        bool band = false ;
        if( i + a.size() - 1 <t.size())
        {
          band = true ;
            bool res = true;

            // 

            ll tmp = hashing.get(i , i + a.size()  ) ;
            
            ll tmp2 = h1.get(0 , a.size() ) ;
            
            if(tmp == tmp2 )
            {
            // cout<<tmp <<" "<<tmp2<<endl;
                ini.push_back({i , i + a.size()  });
            }
        }
        if( i + b.size() - 1 < t.size())
        {
          band = true ;
           ll tmp = hashing.get(i , i + b.size()  ) ;
          
          ll tmp2 = h2.get(0 , b.size() ) ;
          
          if(tmp == tmp2 )
          {
              fin.push_back({i , i + b.size()  });
          }
        }
        if(!band)
        {
          break;
        }

        
    }

    unordered_set <ll >st;
    int iter = 0 ;
    for(int r=iter; r<fin.size(); ++r)
    {
      for(int l=0; l<ini.size(); ++l)
        {
        
            if( ini[l].first <= fin[r].first && ini[l].second <= fin[r].second   )
            {
                ll tmp = hashing.get(ini[l].first , fin[r].second) ;
                st.insert(tmp);
//                cout<<tmp<<endl;
            }
            if( ini[l].first > fin[r].first  )
            {
                iter = r+ 1; 
            }
            if(ini[l].second > fin[r].second)
            {
              break;
            }
        }
    }
    cout<<st.size()<<endl;
    return 0;
}