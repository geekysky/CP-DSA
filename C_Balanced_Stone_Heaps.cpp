#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool checker(vector<int> &arr, int n, int mid)
{
    // check if every mid can be >=mid
    // if yes return true
    // else return false

    int d;
    bool possible = true;
    set<int> indexes;
    for (int i = 2; i < n; i++)
    {
        int max_d = arr[i] / 3;
        int second = ((mid - arr[i - 2] + 1) / 2) <= 0 ? 0 : ((mid - arr[i - 2] + 1) / 2);
        int first = mid - arr[i - 1] <= 0 ? 0 : mid - arr[i - 1];
        int required = max(second, first);

        if(first>0 and second>0){
            //let's see if a[i] can provide to both 
            if(required<=max_d){
                arr[i-2]+=2*required;
                arr[i-1]+=required;
                
                arr[i]-=3*required;
            }
            else if(second>max_d){
                //isko aage koi stones de nahi sakta 
                possible=false;
                break;
            }
            
        }
        else if(first>0){
            if(first<=max_d){
                arr[i-1]+=first;
                arr[i-2]+=first*2;

                arr[i]-=3*first;
            }

            //else let's wait for next index 
        }
        else if(second>0){
            if(second<=max_d){
                arr[i-1]+=second;
                arr[i-2]+=2*second;

                arr[i]-=3*second;
            }
            else{
                possible=false;
                break;
            }
        }
    }

    return possible;
}

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

        // can each pile have >=x stones
        int minVal = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < minVal)
            {
                minVal = arr[i];
            }
        }

        int low = minVal;
        int high = 1e9;
        int ans = high + 1;

        for (int i = 0; i < 100; i++)
        {
            int mid = (low + high) / 2;

            if (checker(arr, n, mid))
            {
                ans = mid;
                low = high + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}