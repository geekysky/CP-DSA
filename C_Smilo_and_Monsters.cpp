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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int s = 0, e = n - 1;
        int sum = 0;
        int moves = 0;

        // kisi bhi individual monster ko ceil(n/2) moves m maar sakte hai...
        while (s <= e)
        {
            sum += arr[s];
            if (s == e)
            {
                // same index take partially from this value and eliminate the same index as a whole
                sum = max(0ll, sum - arr[s]);
                int take = (arr[s] - sum + 1) / 2;
                if (sum >= arr[s] or arr[s] == 1)
                {
                    // no need for power move
                    moves++;
                    break;
                }
                moves += (sum + take + 1);
                sum = 0;
                break;
            }
            if (sum == arr[e])
            {
                moves += (sum + 1);
                sum = 0;
                e--;
                s++;
            }
            else if (sum > arr[e])
            {
                // take partial from current element and rest as remaining
                sum = max(0ll, sum - arr[s]);
                int take = (arr[e] - sum);
                moves += (arr[e] + 1);
                sum = (arr[s] - take);
                e--;
                s++;
            }
            else if (sum < arr[e])
            {
                s++;
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     if (arr[i] != 0)
        //     {
        //         moves += (arr[i]);
        //     }
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << "\n";
        //cout << sum << endl;
        if (sum)
        {
            moves+=(sum+1)/2;

            if(sum>1){
                moves++;
            }
        }
        cout << moves << "\n";
    }
    return 0;
}