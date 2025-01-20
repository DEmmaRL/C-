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


void solve(){

   int n ;
   cin>>n;

   vi a(n), b(n);

   fore(i,0,n){
    cin>>a[i];
   }

   fore(i,0,n){
    cin>>b[i];
   }

   int m; 
   cin>>m ;

   vi v(m);

    map<int , int> mapa;

   fore(i,0,m){
    cin>>v[i];
    mapa[v[i]]++;
   } 

   bool res = true , bandera = false ;

   fore(i,0,n){
    if( a[i] != b[i] ){
        if( mapa[b[i]] >= 1 ){
            mapa[b[i]]--;
            bandera = true ;
        } else {
            res = false ;
            break;
        }
    }
   }

   if(!res){
    cout<<"NO"<<endl;
   } else {
    
    bool tmp = true ;

    for(auto e : mapa){
        if( e.ss >= 1 ){
            tmp = false;
            break;
        }
    }

    if(tmp){
        cout<<"YES"<<endl;
    } else{

        bool search = false ;

        fore(i,0,n){
            if(b[i] == v[m-1]){
                search = true ;
                break ;
            }
        }

        if(search){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }

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