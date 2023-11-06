#include <bits/stdc++.h>
#define fore(i,a,b) for(long long i = (a), ThxMK = (b); i < ThxMK; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long int lli;
vector<lli>criba;
const lli MAX=300+7;
bool vis[MAX+1];
void fun()
{
vis[0]=true;
vis[1]=true;
  for(lli i=2; i*i<=MAX; ++i)
  {
    if(!vis[i])
    {
      for(lli j=i*i; j<=MAX; j+=i)
      {
        vis[j]=true;
      }
    }
  }
  for(lli i=0; i<=MAX; ++i)
  {
    if(!vis[i])
    {
      criba.push_back(i);
    }
  }

}
int main(){
    _
  
    lli n;
    cin>>n;
    fun();
    if(n==2)
    {
      cout<<1<<endl;
      return 0;
    }
    lli arr[n+1];
    for(lli i=0; i<=n; ++i)

    {
        arr[i]=0;
    }

    for(lli i=0; criba[i]<=n; ++i)
    {
   //     cout<<criba[i]<<endl;
        lli mult=1 + max(lli(0), arr[criba[i]]-1);
        
        
        int j=1;
        while(j<=n)
        {
            if( criba[ i + j ] <= n && criba[ i + j ] - criba[ i]  <= 14 )
            {
          //      cout<<criba[i+j]<<" mas "<<mult<<endl;
            arr[criba[i+j]]+=mult;
            }
            else{
break;            }
j++;
        }
    }
cout<<arr[n]<<endl;

}

