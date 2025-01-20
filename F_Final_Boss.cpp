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
using vi = vector<lli>;
using pii = pair<int, int>;

const int MOD  = 1e9 + 7 ;

void solve(){
    
    lli h, n;
    cin>>h>>n;

    vector< pair<lli,lli> > v(n);
    lli primero = 0 ;
    fore(i,0,n){
        int a ;
        cin>>a;
        v[i].ff=a;
        primero+=a;
    }
    fore(i,0,n){
        int b;
        cin>>b;
        v[i].ss = b ;
    }
    lli cont = 1 ;
    h-=primero;

    if(h <= 0 ){
        cout<<1 <<endl;
        return ;
    }
    
    //cout<<h<<endl;

    priority_queue <pair<lli, lli>, vector< pair<lli,lli> >, greater< pair<lli,lli> >> cola ;

    fore(i,0,n){

        cola.push( { 1 + v[i].ss , i } );

    }

    while( h > 0 ){

        h-= v[cola.top().ss].ff ;
        cont = max(cola.top().ff , cont) ;
        cola.push( { cola.top().ff + v[cola.top().ss].ss , cola.top().ss } );
        cola.pop();
    }

    cout<<cont<<endl;
}


int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}