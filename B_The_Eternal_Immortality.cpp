#include<bits/stdc++.h>
using namespace std;
#define int long long int 
const int mod=10;

signed main(){
    int a,b;
    cin>>a>>b;
    
    //after every 10 multiplications remainders become 0...so we stop when remainder becomes zero 
    int ans=1;
    for(int i=a+1;i<=b;i++){
        ans=((ans%10)*(i%10))%10;

        if(ans==0){
            break;
        }
    }

    cout<<ans<<"\n";

    return 0;
}