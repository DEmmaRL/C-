#include <bits/stdc++.h>
#define lli long long int
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

vi kmppre(string& t){
  vi r(t.size()+1);
  r[0] = -1; int j = -1;
  fore(i,0,t.size()){
    while(j >= 0 && t[i] != t[j])
      j = r[j];
    r[i+1] = ++j;
  }
  return r;
}

// Encontrar t en s
vector<pair<int,int> > kmp(string& s, string& t){
  vector<pair<int,int> > res ;
  int j = 0; vi b = kmppre(t);
  fore(i,0, s.size() ){
    while(j >= 0 && s[i] != t[j])
      j = b[j];
    if(++j == t.size() ){
        res.pb( {i-j+1 , ( (i-j+1) + t.size() ) - 1 } ) ; 
        //cout << "Match en index " << i-j+1 << ENDL;
        j = b[j];
      } 
  }
  return res ;
}

void solve() {
    //cout<<"E";
    string s; 
    cin>>s ;

    int n ;
    cin >> n ;

    vector< pair<int,int> > ranges[n];

    vector<map<int,int> > mapa(s.size() );

    fore(i,0,n){
        string tmp ;
        cin>>tmp;
        ranges[i] = kmp( s , tmp );
    }

    fore(i,0,n){
        for(auto e: ranges[i]){
            //cout<<"El string "<<i<< "aparece en " << e.first<<" - "<< e.second<<endl ;
            
            if( e.second == e.first ){
                mapa[e.first][i] = -2 ;
            }
            else {
                if( mapa[e.first][i] == -1 ){
                    mapa[e.first][i] = -5 ;
                } else 
                    mapa[e.first][i] = 1 ;
                
                if( mapa[e.second][i] == 1 )
                    mapa[e.second][i] = -5 ;
                else
                    mapa[e.second][i] = -1 ;
            }
            
        }
    }

    int res = 0 , tam = 0 ;

    int l = 0 , r = 0 ;

    vector<int> v(n,0) ;

    while( l <= r && r < s.size() ){
        int act = 0 ;

        set<int> tmp ;

        for(auto e: mapa[r]){

        

            if( e.second == -1 && v[e.first] >= 1 ){
                
                

                if(act != 2) act = 1 ;
                if( r == 11 ){
                 //   cout<<"AAAAAAAAAAAAAAAAA "<<act<<endl;
                }
                tmp.insert( e.first );
            }
            if( e.second == 1 ){
                //cout<<"en "<<r<<" empieza "<<e.first<<endl ;
                v[e.first]++ ;
            } if( e.second == -5 ){
                if( v[e.first] >= 1 ){
                    if(act != 2) act = 1 ;
                    tmp.insert(e.first) ;
                }
                v[e.first]++;
            }
            if( e.second == -2 ){ // We find a string of size 1
                act = 2 ;
            }
        }
        if(r == 11 ){
          //  cout<<"EEEEEEEE "<<act<<endl;
        }
        //cout<<endl;
        //cout<<l<<" "<<act<<endl;
        if( act == 2 ){ // Nos saltamos todo
            fore(i,0,n) 
                v[i] = 0 ;
            r++;
            l=r;
            continue;
        } else if( act == 1 ){
           // cout<<"aaa "<<l<<" "<<r<<endl;
            while( tmp.size() >= 1 ){
                
                for(auto e: mapa[l]){
                    if( e.second == 1 or e.second == -5 ){
                        v[e.first]-- ;
                        if( tmp.find(e.first) != tmp.end() )
                            tmp.erase(e.first);
                    }
                }

                l++;
            }

        }
        else if(tam < (r - l) + 1 ) {

            tam = (r - l) + 1 ;
            res = l ;

           // cout<<l<<" "<<r<< " " << tam << endl ;
        }
        ++r;
    }

    cout<< tam << " " << res << endl ;

}

int main() {
    IO;
    int t = 1; 
    //cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}
