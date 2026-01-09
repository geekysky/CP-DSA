#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int x,y;
        cin>>x>>y;
        
        int n=2*(x-y);
        cout<<n<<"\n";
        for(int i=y;i<x;i++){
            cout<<i<<" ";
        }
        for(int i=x;i>=(y+1);i--){
            cout<<i<<" ";
        }

        cout<<"\n";

    }

    return 0;
}