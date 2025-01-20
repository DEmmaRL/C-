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

const int MOD  = 1e9 + 7 ;

void solve(){
    
    int n ;
    cin>>n;

    int res  = 0, tmp ;

    fore(i,2,n+1){

        int cont = 0 ;

        for(int j=i; j <= n ; j+= i ){
            cont+=j;
        }


        if(res < cont){
            res = cont;
            tmp = i ;
        }
    }

    cout<<tmp<<endl;
}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}