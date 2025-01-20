#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for(lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

void solve() {
    int n ;
    cin>>n;
    map<int, int> mapa ;

    fore( i,0,n ){
        int tmp ;
        cin>>tmp;

        mapa[tmp]++;
    }

    if(mapa.size()>2){
        cout<<"NO"<<endl ;
    } else {
        if( mapa.size() == 1 ){
            cout<<"YES"<<endl ;
        }
        else{
            int arr[2] , b = 0 ;

            for(auto e : mapa){
                arr[b] = e.ss ;
                b++;
            }

            if(abs(arr[0] - arr[1]) <= 1 ){
                cout<<"YES"<<endl ;
            } else {
                cout<<"NO"<<endl ;
            }
        }
    }
}

int main() {
    IO;
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
