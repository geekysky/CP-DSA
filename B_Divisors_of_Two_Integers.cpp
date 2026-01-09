#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    if (n == 2)
    {
        cout << arr[0] << " " << arr[1] << "\n";
        return 0;
    }

    sort(arr.begin(), arr.end());
    int first = -1, y = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        map<int, int> copy = mp;
        bool x = true;

        for (int j = 1; j * j <= arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                int factor1 = j, factor2 = arr[i] / j;

                if (factor1 == factor2)
                {
                    if (copy[factor1] < 1)
                    {
                        x = false;
                        break;
                    }
                    copy[factor1]--;
                }
                else
                {
                    if (copy[factor1] < 1 || copy[factor2] < 1)
                    {
                        x = false;
                        break;
                    }
                    copy[factor1]--;
                    copy[factor2]--;
                }

                if (copy[factor1] == 0)
                    copy.erase(factor1);
                if (copy[factor2] == 0)
                    copy.erase(factor2);
            }
        }

        if (x && !copy.empty())
        {
            auto it = copy.rbegin();
            first = arr[i];
            y = it->first;
            break;
        }
    }

    cout << first << " " << y << "\n";

    return 0;
}