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

        vector<int> arr(n), even, odd;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                even.push_back(arr[i]);
            else
                odd.push_back(arr[i]);
        }

        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());

        int i = 0, j = 0, k = 0, sum1 = 0, sum2 = 0;
        while (k < n)
        {
            if (k % 2 == 0)
            {
                // alice's turn
                if (j == odd.size() and i < even.size())
                {
                    sum1 += even[i];
                    i++;
                }
                else if (i < even.size() && even[i] > odd[j])
                {
                    sum1 += even[i];
                    i++;
                }

                else
                {
                    j++;
                }
            }
            else
            {
                // bob's turn
                if (i == even.size() and j < odd.size())
                {
                    sum2 += odd[j];
                    j++;
                }
                else if (j < odd.size() && odd[j] > even[i])
                {
                    sum2 += odd[j];
                    j++;
                }

                else
                {
                    i++;
                }
            }
            k++;
        }

        if (sum1 > sum2)
            cout << "Alice\n";
        else if (sum1 < sum2)
            cout << "Bob\n";
        else
            cout << "Tie\n";
    }
    return 0;
}