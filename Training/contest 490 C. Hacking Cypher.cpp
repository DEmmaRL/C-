#include<bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define f first
#define s second
#define fore(i,a,b) for(int i=(a), ThxMK = (b); i < ThxMK; ++i)
#define sz(s) int(s.size())
//freopen("Round1.in", "r", stdin);
// r = read  || stdin = standard input
//freopen("out", "w", stdout);
// w = write || stdout = standard output

typedef long long ll;
using namespace std;
 //g++ main.cpp && a < input.txt > output.txt
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int a, b;
    cin>>a>>b;

    int tmp = 0 , tmp2= 0 ;
    int suf[s.size()];

    vector<int>diez(s.size());
    
    for(int i=s.size()-1; i>=0; --i)
    {
        if(i == s.size()-1)
        {
            diez[i]=1;
        }
        else
        {
            diez[i] = ( (diez[i+1]) * 10 ) % b ;
        }
    }


    for(int i=s.size()-1 ; i >= 0 ;--i)
    {
        if( i < s.size()-1 )
        {
            s[i]-='0';
            suf[i]= ( ( ( s[i] * diez[i] ) % b ) + (suf[i + 1 ] % b ) ) % b ;
        }    
        else
        {
            s[i]-='0';
            suf[i] = s[i] % b ;
            

        }
    }

    for(int i=0; i<s.size(); ++i)
    {
      int k =  s[i] ;   

      tmp= ( ( tmp * 10 ) + k ) % a ;
      //cout<<tmp<<endl;
      if( tmp == 0  && i + 1 < s.size() && suf[ i + 1 ] == 0  )
      {
        if(s[i+1] == 0)
        {
          continue;
        }
        
        cout<<"YES"<<endl;

        for(int h=0; h<=i; ++h)
        {
            cout<<(char)(s[h]+'0');
        }
        cout<<endl;
        for(int h=i+1; h<s.size(); ++h)
        {
            cout<<(char)(s[h]+'0');
        }
        cout<<endl;
        return 0;

          
      }


    } 



    cout<<"NO"<<endl;

    return 0;
}