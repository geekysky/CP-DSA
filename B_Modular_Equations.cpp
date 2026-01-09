#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int a,b;
    cin>>a>>b;

    if(a-b==0){
        cout<<"infinity"<<"\n";
    }
    else if(b>a){
        cout<<0<<"\n";
    }
    else{
        set<int> factors;
        for(int i=1;i*i<=(a-b);i++){
            if((a-b)%i==0){
                factors.insert(i);
                factors.insert((a-b)/i);
            }
        }

        int ans=0;
        for(auto ele:factors){
            if(a%ele==b){
                ans++;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}