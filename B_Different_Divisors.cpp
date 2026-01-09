#include <bits/stdc++.h>
using namespace std;
#define int long long int

int lcm(int pref,int curr){
    return ((pref*curr)/__gcd(pref,curr));
}

signed main()
{
    vector<int> is_prime(1e6 + 1, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    int len = 1e6;

    for (int i = 2; i <= len; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= len; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
    
    vector<int> next_prime(len + 1, 0);

    int last_prime = -1;
    for (int i = len; i >= 2; i--)
    {
        if (is_prime[i])
        {
            last_prime = i;
        }
        next_prime[i] = last_prime;
    }

    int t;
    cin>>t;

    while(t--){
        int d;
        cin>>d;
        
        int factors=1;
        int num=1;
        int ans=1;

        while(true){
            int next=next_prime[num+d];
            factors++;
            ans=lcm(ans,next);

            if(factors==3){
                break;
            }
            num=next;
        }

        cout<<ans<<"\n";

    }
    return 0;
}