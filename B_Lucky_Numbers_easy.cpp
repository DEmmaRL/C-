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

set<lli> dp ;

#define MAX (1e10+7)

void fun( lli n ){
    if(n > MAX) return ;

    string s = to_string(n) ;
    unordered_map<char, int> mapa ;
    fore(i,0,s.size())
        mapa[s[i]]++ ;
    if(mapa['4'] == mapa['7'] )
    dp.insert( n ) ;

    string a = s  , b = s;
    a+="4" , b+="7";
    fun(stoll(a)) ;
    fun(stoll(b)) ;
}

void solve(int t) {
    
    lli  n ;
    cin>>n ;

    fun(4);
    fun(7);

    auto it = dp.lower_bound( n ) ;

    cout<<*it<<endl;


}

int main() {
    IO;
    
    int t = 1;
    
    fore(i,1,t+1) {
        solve(i);
    }

    return 0;
}
