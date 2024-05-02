#include<bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
//freopen("Round1.in", "r", stdin);
// r = read  || stdin = standard input
//freopen("out", "w", stdout);
// w = write || stdout = standard output
 
using namespace std;
typedef unsigned long long int lli;
 //g++ main.cpp && a < input.txt > output.txt
 
struct segmentree
{
  int size;
  vector<lli>sums;
  
  void init(int n)
  {
    size = 1 ;

    while(size < n)
    size*=2;

    sums.assign( 2*size , 0LL );
  }

  void build( vector<int> &a, int x , int lx, int rx)
  {
    if( rx - lx == 1 )
    {
      if( lx < a.size() )
      {
        sums[x] = a[lx];
      }
      return  ;
    }
    int m = (lx + rx) / 2 ;

    build(a , 2 * x + 1 , lx,  m );

    build(a , 2 * x + 2 , m,  rx );

    sums[x] = sums[2 * x  + 1 ] + sums[2 * x  + 2 ];
  }

  void build( vector<int> &a )
  {
    build( a , 0 , 0 , size );
  }

  void set(int i , int v, int x , int lx, int rx)
  {
    if( rx - lx == 1 )
    {
      sums[x] = v ;
      return ; 
    }
    int m = (lx + rx) / 2 ;

    if(i < m)
    {
      set( i , v , 2 * x + 1 , lx , m );
    }
    else
    {
      set( i , v , 2 * x + 2 , m , rx );
    }
    sums[x] = sums[ 2 * x + 2 ] + sums[ 2 * x + 1 ] ; 
  }
  
  void set(int i , int v)
  {
    set( i , v , 0 , 0 , size );
  }

  lli sum( int l, int r, int x, int lx, int rx )
  {
    if( lx >= r || rx <= l  ) return 0 ;

    if( lx >= l && rx <= r )
    return sums[x];

    int m = (lx + rx) / 2 ;

    lli s1 = sum( l , r , 2 * x + 1 , lx , m );
    lli s2 = sum( l , r , 2 * x + 2 , m , rx );

    return s1 + s2 ;

  }

  lli sum( int l, int r)
  {
    return sum(l, r, 0 , 0 , size);
  }


};


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n , q;
    cin>>n >> q ;

    segmentree st;

    st.init(n);

    vector<int>v(n);

    for(int i=0; i<n; ++i)
    {
      cin>>v[i];
    }

    st.build(v);

    while(q--)
    {
      int op;
      cin>>op;
      if(op ==1 )
      {
        int i, a;
        
        cin>>i>>a;

        st.set( i , a);

      } 
      else
      {
        int l, r;
        cin>>l>>r;

        cout<<st.sum(l , r )<<endl;
      }
    }


    

    return 0;
}