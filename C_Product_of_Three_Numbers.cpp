#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        
        // Find its prime factorization
        map<int, int> mp;
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {
                mp[i]++;
                n /= i;
            }
        }
        
        // If there's any remaining prime factor greater than sqrt(n), it will be left in n.
        if (n > 1)
        {
            mp[n]++;
        }

        // Case 1: More than 2 distinct prime factors
        if (mp.size() > 2)
        {
            cout << "YES" << "\n";
            vector<int> factors;
            int temp=0;
            int rem=1;
            for (auto it : mp)
            {   
                if(temp<2)
                factors.push_back(pow(it.first, it.second));

                else
                rem*=pow(it.first, it.second);

                temp++;
            }
            factors.push_back(rem);
            for (int factor : factors)
            {
                cout << factor << " ";
            }
            cout << "\n";
        }

        // Case 2: Exactly 2 distinct prime factors
        else if (mp.size() == 2)
        {
            int one = mp.begin()->first;
            int two = mp.rbegin()->first;
            int oneCount = mp.begin()->second;
            int twoCount = mp.rbegin()->second;

            if (oneCount + twoCount > 3)
            {
                cout << "YES" << "\n";
                int factor1 = pow(one, 1);
                int factor2 = pow(two, 1);
                int factor3 = pow(one, oneCount - 1) * pow(two, twoCount - 1);
                cout << factor1 << " " << factor2 << " " << factor3 << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }

        // Case 3: Exactly one factor
        else
        {
            int cnt = mp.begin()->second;

            if (cnt >= 6)
            {
                int one = mp.begin()->first;
                int two = pow(mp.begin()->first, 2);
                int three = pow(mp.begin()->first, cnt - 3);
                cout << "YES" << "\n";
                cout << one << " " << two << " " << three << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}
