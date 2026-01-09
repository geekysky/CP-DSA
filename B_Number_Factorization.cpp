#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        map<int, int> mp;
        int num = n;

        for (int i = 2; i * i <= n; i++)
        {
            if (num % i == 0)
            {
                int cnt = 0;
                while (num % i == 0)
                {
                    cnt++;
                    num /= i;
                }
                mp[i] = cnt;
            }
        }
        if (num > 1)
            mp[num] = 1;

        int ans = 0;
        
        //map at max log 2 n times iterate hoga entirely... -> 30
        while (!mp.empty())
        {
            int temp = 1;
            for (auto it = mp.begin(); it != mp.end();)
            {
                temp *= it->first;
                it->second--;
                if (it->second == 0)
                    it = mp.erase(it);
                else
                    ++it;
            }
            ans += temp;
        }

        cout << ans << '\n';
    }

    return 0;
}
