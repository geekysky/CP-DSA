#include <bits/stdc++.h>
using namespace std;
#define ll long long

int prime_factorize(int num){
    set<int> s;
    
    for(int i=2;i*i<=num;i++){
        while (num%i==0)
        {
            /* code */
            s.insert(i);
            num/=i;

        }
        
    }

    if(num>1){
        s.insert(num);
    }

    return s.size();
}

int main()
{
    int n;
    cin >> n;

    int ans = 0;

    if (n == 1)
    {
        cout << 0 << "\n";
    }

    else
    {
        for (int i = 2; i <= n; i++)
        {
            int cnt=prime_factorize(i);

            if(cnt==2){
                ans++;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}