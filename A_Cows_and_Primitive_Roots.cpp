#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1e9+7;

signed main(){
    int p;
    cin>>p;

    //p2 
    int ans=0;
    for(int i=1;i<=p-1;i++){
        int f=true;
        int curr=1;
        for(int j=1;j<=p-2;j++){
            curr=(curr*i)%p;

            if(curr==1){
                f=false;
                break;
            }
        }

        if(f){
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}