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

#define PI 3.141592

double tangente =  0 ;
pair<double, double> f( double angulo , double x , double h ) {

    double l = h / tangente ; 
    return { x , l + x } ;
}

void solve() {
	double angulo ;
    int n ;
    cin>>angulo>>n ;

    vector<pair<double, double> > v(n);
    tangente =  tan( angulo * PI / 180.0 ) ;
    fore(i,0,n){
        int x, h;
        cin>>x>>h;
        v[i] = f( angulo , x , h );
    }
    sort(all(v)) ;

    pair<double,double> a = v[0]; 

    double res = 0 ;

    fore(i,1,n){
        if( a.ss >= v[i].ff ){
            a.ss = max( a.ss , v[i].ss );
        }        
        else{
            res+= a.ss - a.ff  ;
            a.ff = v[i].ff;
            a.ss = v[i].ss;
            
        }
    }
    res+= a.ss - a.ff  ;

    cout << fixed << setprecision(15)<<res<<ENDL;

}
 

int main() {
    IO;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
