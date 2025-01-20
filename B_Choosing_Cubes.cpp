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

   int n, f, k;
   cin>>n>>f>>k; 

   vi v(n);

   fore(i,0,n){
    cin>>v[i];
   }

   f = v[f-1];

   sort(v.rbegin(), v.rend());

    int cur = v[k - 1 ];

    if(cur > f){
        cout<<"NO"<<endl;
    } else if( cur < f ){
        cout<<"YES"<<endl;
    } else{

        if( k + 1 <= n && v[ k ] == f ){
            cout<<"MAYBE"<<endl;
        } else{
            cout<<"YES"<<endl;
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