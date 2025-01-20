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

struct segmenTreeNode
{
  int minimo ;
  int curr ;
  int cont ;
};

struct segmentree
{
  int size;
  vector<segmenTreeNode>tree;
  
  void init(int n)
  {
    size = 1 ;

    while(size < n)
    size*=2;

    tree.assign( 2*size );
  }

  void build( vector<int> &a, int x , int lx, int rx)
  {
    if( rx - lx == 1 )
    {
      if( lx < a.size() )
      {
        tree[x].minimo = a[lx];
        tree[x].curr = a[lx];
        tree[x].cont = 1;
      }
      return  ;
    }
    int m = (lx + rx) / 2 ;

    build(a , 2 * x + 1 , lx,  m );

    build(a , 2 * x + 2 , m,  rx );

    //tree[x].minimo = min( tree[2 * x  + 1 ] , tree[2 * x  + 2 ] );
  
    int min1 = tree[2 * x  + 1 ].minimo, min2 = tree[2 * x  + 2 ].minimo;
    
    if(min1  == min2 )
    {
      tree[x].cont = tree[2 * x  + 1 ].cont + tree[2 * x  + 2 ].cont;
    }
    else if( min1 < min2)
    {
      tree[x].cont = tree[2 * x  + 1 ].cont ;
    }
    else
    {
      tree[x].cont = tree[2 * x  + 2 ].cont ;
    }
  }

  void build( vector<int> &a )
  {
    build( a , 0 , 0 , size );
  }

  void set(int i , int v, int x , int lx, int rx)
  {
    if( rx - lx == 1 )
    {
      tree[x].curr = v ;
      tree[x].cont = 1 ;
      tree[x].minimo = v ;
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
    
    int min1 = tree[2 * x  + 1 ].minimo, min2 = tree[2 * x  + 2 ].minimo;
    
    if(min1  == min2 )
    {
      tree[x].cont = tree[2 * x  + 1 ].cont + tree[2 * x  + 2 ].cont;
    }
    else if( min1 < min2)
    {
      tree[x].cont = tree[2 * x  + 1 ].cont ;
    }
    else
    {
      tree[x].cont = tree[2 * x  + 2 ].cont ;
    }

    
  }
  
  void set(int i , int v)
  {
    set( i , v , 0 , 0 , size );
  }

  lli minimo( int l, int r, int x, int lx, int rx )
  {
    if( lx >= r || rx <= l  ) return -1 ;

    if( lx >= l && rx <= r )
    {
      return tree[x].cont;
    }
    
    int m = (lx + rx) / 2 ;

    lli s1 = minimo( l , r , 2 * x + 1 , lx , m );
    lli s2 = minimo( l , r , 2 * x + 2 , m , rx );

    if(s1 > s2)
    swap(s1, s2);

    if(s1 >=0 )
    {
      return s1 ;
    }
    else
    {
      return s2 ;
    }

  }

  lli minimo( int l, int r)
  {
    return minimo(l, r, 0 , 0 , size);
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

        cout<<st.minimo(l , r )<<endl;
      }
    }


    

    return 0;
}