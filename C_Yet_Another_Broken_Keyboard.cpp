#include<bits/stdc++.h>
#define ENDL '\n'

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int lli;
#define pb push_back 
#define f first
#define s second 
#define sz(s) int( s.size() ) 
 //g++ main.cpp && a < input.txt > output.txt

int main(){
  _

  int n , k ;
  cin>>n>>k;

  string s ;
  cin>>s;

  set<char> st ;

  for(int i=0; i < k ; ++i ){
    char a ;
    cin >> a ; st.insert(a) ;
  }

  lli res = 0 ;

  for( int i = 0 ; i < s.size(); ++i ){

    if( st.find(s[i]) != st.end() ){

        lli cur = 0 , iter = i , fin = i ;

        while( fin < s.size() && st.find( s[ fin ] ) != st.end()  ){
            fin++;
        }
        if(fin!=iter) fin--;

        cur = (fin - iter) + 1 ;

        i = fin ;

        res += (cur * (cur + 1 ) ) / 2 ;
    }
  }

  cout<<res<<endl;

   return 0;
}