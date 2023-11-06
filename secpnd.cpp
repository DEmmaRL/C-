#include <bits/stdc++.h> 
typedef long long int lli;
using namespace std;
 
lli total = 0 ;
lli cant = 0 ;

vector<int>tam(100+1);


struct prefix_tree
{
    vector< map<char, pair<int , int> > > trie;
    vector<bool> isw;

    prefix_tree()
    {
        new_node();
    }

    int new_node()
    {
        trie.push_back(map<char, pair<int, int> >());
        isw.push_back(false);
        return trie.size() - 1;
    }

    void insert(string &s, int u = 0)
    {
        for(char c: s)
        {
            if( !trie[u][c].first )
            {
                trie[u][c].first = new_node();
                trie[u][c].second=1;
            }
            else
            {
                trie[u][c].second++;
            }
            u = trie[u][c].first;
        }
        isw[u] = true ;
    }

    bool dfs(int u = 0 )
    {
        int i=1;
        for(auto c : trie)
        {
            cout<<"en el mapa "<<i<<endl;
            for(auto k : c)
            {
                cout<<k.first<<" "<<k.second.second<<" ";

                if(k.second.second >= tam[i] )
                {
                    tam[i]=k.second.second;
                   // total = k.second.second;
                   // cant = i ;
                }
            }
            cout<<endl;
            i++;
        }
        return 0;
    }

    bool find(string &s, int u = 0 )
    {
        for(char c : s)
        {
            if(!trie[u][c].first)
            {
                return false;
            }
            u = trie[u][c].first;
        }
        //return true;
        return isw[u];
    }

};

 
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    for(int c=1; c<=t; ++c)
    {

        tam.clear();
        tam.resize(101, 0);
        

        prefix_tree trie = prefix_tree();
        int n;
        cin>>n;
        for(int i = 0; i<n; ++i )
        {
            string aux;
            cin>>aux;

            string aux2="";
            aux2.resize(aux.size());

            for(int j=0; j<aux.size(); ++j)
            {
                aux2[j] = tolower(aux[ aux.size() - j - 1 ]);
            }

           // reverse(aux.begin(), aux.end());

            trie.insert(aux2);
         //   cout<<aux2<<" ";
        
        }
            cant = 0;
            total = 0;
            trie.dfs();

        int res=INT_MAX, cont = -1;
        for(int i=1; i<=100; ++i)
        {
            if( tam[i] < n - 1 && tam[i] )
            {
                res = tam[i];
                cont = i ;
            }
        }


        cout<<"Case "<<c<<":"<<endl;
        cout<<cont<<" "<<res<<endl;

    }


/*
   prefix_tree trie = prefix_tree();

    string s="holt";

   trie.insert( s );

   s="holt";

   trie.insert( s );

   cout<<trie.dfs()<<endl;

    cout<<cant<<" "<<total<<endl;
*/
    return 0;
}