#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9+7;

int modular_exponentiation(int a, int b){
    int res=1;
    while(b>0){
        if(b%2==1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return res;
}

int modular_multiplication(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}

signed main(){
    int n;
    cin>>n;

    int triangles=n;
    int ans=1;
    for(int i=0;i<n;i++){
        ans=modular_multiplication(ans,7);
    }
    ans=(modular_exponentiation(3,3*n)%mod - ans%mod + mod)%mod;
    cout<<ans<<endl;

    return 0;
}