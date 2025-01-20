#include<bits/stdc++.h>
#define ENDL '\n'

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int lli;
#define pb push_back 
#define f first
#define s second 
 //g++ main.cpp && a < input.txt > output.txt

int main(){
  _

  //ifstream fin("input.txt");
  //ofstream fout("output.txt");

  bool res = false ;

  int n ;
  cin>>n;
  vector<int>v(n);

  for(int i=0; i<n; ++i){
    cin>>v[i];
    v[i]--;
  }

  for(int i=0; i<n; ++i){

    if( v[ v[ v[ i ] ] ] == i ){
        res = true ;
        break ;
    }

  }

  if(res){
    cout<<"YES"<<endl;
  } else{
    cout<<"NO"<<endl;
  }

   return 0;
}