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
using vi = vector<int>;
using pii = pair<lli, lli>;

void solve() {
    int n ;
    cin>>n ;
    string s ;
    cin>> s ;

    map<char,int> mapa ;

    fore(i,0,n){
        mapa[s[i]]++;
    }

    int zero = 0 , uno = 0 ;

    string a = "zero" , b = "one";
    int mini = 1e9 ;
    fore(i,0,b.size()){
        mini = min(mini, mapa[b[i]]);
    }
    uno = mini ;
    zero = mapa['z']  ;

    fore(i,0,uno){
        cout<<1<<" ";
    }
    fore(i,0,zero){
        cout<<0<<" ";
    }
    cout<<endl;

}

int main() {
    IO;
    //int t = 1;while (t--)
        solve();
    

    return 0;
}
