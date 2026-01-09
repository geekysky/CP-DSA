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

        string s;
        cin >> s;

        vector<int> pref_sum(n+1, 0);

        for(int i = 0; i < n; i++){
            pref_sum[i+1] = pref_sum[i] + arr[i];
        }

        int low = 1, high = n;
        int ans_sum = 0;

        while(low <= high){
            if(s[low-1] == 'L' && s[high-1] == 'R'){
                ans_sum += (pref_sum[high] - pref_sum[low-1]);
                low++;
                high--;
            }
            else if(s[low-1] == 'R'){
                low++;
            }
            else if(s[high-1] == 'L'){
                high--;
            }
            else {
                low++;
                high--;
            }
        }

        cout << ans_sum << "\n";
    }

    return 0;
}
