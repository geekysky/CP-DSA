#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;

int power(int a, int b)
{
    int result = 1;
    while (b)
    {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int mod_multiply(int a,int b){
    return (a%mod * b%mod) % mod;
}

signed main()
{
    int n,m;
    cin>>n>>m;

    vector<int> factorial(2e6 + 1), inverse(2e6 + 1);
    factorial[0] = 1;
    for (int i = 1; i <= 2e6; i++)
    {
        factorial[i] = ((factorial[i - 1] % mod) * (i % mod)) % mod;
    }

    inverse[2e6] = power(factorial[2e6], mod - 2);
    for (int i = 2e6 - 1; i >= 0; i--)
    {
        inverse[i] = ((i + 1) % mod * inverse[i + 1] % mod) % mod;
    }

    //now just compute m+n-1 C n-1 
    int ans=mod_multiply(factorial[m+n-1],inverse[n-1]);
    ans=mod_multiply(ans,inverse[m]);

    cout<<ans<<"\n";
    
    return 0;
}