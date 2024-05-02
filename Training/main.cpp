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

  string a, b, c;
  cin>>a>>b>>c;

  map<string,int>mapa;

  mapa[ "C" ] = 1 ;
  mapa[ "C#" ] = 2 ;
  mapa[ "D" ] = 3 ;
  mapa[ "D#" ] = 4 ;
  mapa[ "E" ] = 5 ;
  mapa[ "F" ] = 6 ;
  mapa[ "F#" ] = 7 ;
  mapa[ "G" ] = 8 ;
  mapa[ "G#" ] = 9 ;
  mapa[ "A" ] = 10 ;
  mapa[ "B" ] = 11 ;
  mapa[ "H" ] = 12 ;

  vector<int>v;
  v.pb(mapa[a]);
  v.pb(mapa[b]);
  v.pb(mapa[c]);

  for(int i=0; i<3;++i)
  {
    sort(v.begin(), v.end());

    if( v[ 1 ] - v [ 0 ] == 4 && v[2] - v[1] == 3  )
    {
      cout<<"major"<<endl;
      return 0 ;
    }
    if( v[ 1 ] - v [ 0 ] == 3 && v[2] - v[1] == 4  )
    {
      cout<<"minor"<<endl;
      return 0 ;
    }


    v[0]+=12;
  }

  cout<<"strange"<<endl;

   return 0;
}