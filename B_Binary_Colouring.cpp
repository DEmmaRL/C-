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

    lli n ; 
    cin >> n ;

    vi v(31,0);
    //0111
    for(int i=0; i < 30 ; ++i){
        //cout<<(1ll & ( n >> i ) );
        if(1ll & ( n >> i ) ){
            
            if( v[ i ] ){
            
                v[ i ] = 0 ;
                v[ i + 1 ] = 1 ;
            }
            else{
                if( v[i] == 0 && ( i - 1 < 0 || i - 1 >= 0 && v[i-1] == 0 ) ){
                    v[i]=1;
                } else if( i - 1 >= 0 ){
                    v[i] = 0 ;
                    v[i-1] = -1 ;
                    v[i+1] = 1 ;
                }
            }

        }
    }
    //cout<<endl;
    cout<<31<<endl;
    for(int i=0; i<v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;

}
 
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}