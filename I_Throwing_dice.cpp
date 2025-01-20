#include <bits/stdc++.h>

using namespace std ;

typedef long long int lli ;

void solve(){

    int n,m;
    cin>>n>>m;

    lli a = 0 , b = 0 ; 


    for(int i=0; i <n ; ++i){
        int tmp ;
        cin>>tmp; 
        a+=tmp;
    }
    for(int i=0; i <m ; ++i){
        int tmp ;
        cin>>tmp; 
        b+=tmp;
    }

    if(a>b){
        cout<<"ALICE"<<endl ;
    } else if(b>a){
        cout<<"BOB"<<endl;
    } else {
        cout<<"TIED"<<endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}