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

const int MAX = 1e6 +7 ;

int arr[MAX] ;

void solve(){
    int n ;
    cin>>n;
 
    fore(i,0,n){
        int tmp ; cin>>tmp ;
        arr[tmp]++;
    }

    vector<int>v;
 
    fore(i , 0 , MAX ) {
        if(arr[i]) v.pb(i) ;
    }
 
    string a = "Alicius" , b = "Bobius";
 
    if( sz( v ) == 1 || v[0] != 1 ){
 
        cout<<a<<endl ;
 
    } else {
 
        int cont = 0 ;
 
        fore(i, 1 , sz(v)){
            if( v[i] - 1 == v[i-1] ){
                cont++;
            } else break ;
        }
        cont++;
 
        if(cont==n){
            n--;
        }
        //cout<<cont<<endl;
 
        if(cont%2==0){
            cout<<a<<endl; 
        } else {
            cout<<b<<endl;
        }
 
    }
}
 
int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}