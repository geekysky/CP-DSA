#include <bits/stdc++.h>
using namespace std;
#define int long long int

// vector<long long> mergeAdjacent(vector<int> &nums)
// {
//     int l = -1, r = 1;
//     int n = nums.size();
//     vector<long long> res;

//     int prev_running_replacement_sum = 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (nums[i] == nums[i + 1])
//         {
//             int x = nums[i];
//             l = (i==0?-1:i-1);
//             r = (i+1==n-1?n:i+2);

//             //priority to left always...
//             int nxt_check = x*2;

//             while((nums[l]==nxt_check or nums[r]==nxt_check) and (l>=0 or r<n)){
//                 if(l>=0 and nums[l]==nxt_check){
//                     nxt_check*=2;
//                     l--;
//                 }
//                 else if(r<n and nums[r]==nxt_check){
//                     nxt_check*=2;
//                     r++;
//                 }
//             }

//             prev_running_replacement_sum = nxt_check/2;
//             //segment formed is [l-1,r-1]

//         }
//         else
//         {
//             l = i - 1;
//             r = i + 1;

//             prev_running_replacement_sum=nums[i];
//         }
//     }
// }

long long countSubarrays(vector<int> &nums, long long k)
{
    long long ans = 0;
    int l = 0;
    multiset<int> ms;

    int n = nums.size();
    for (int r = 0; r < n; r++)
    {
        ms.insert(nums[r]);

        long long diff = ((*ms.rbegin() - *ms.begin()) * (r - l + 1));
        while (diff > k)
        {
            int ele = nums[l];
            ms.erase(ms.find(ele));
            l++;

            if (!ms.empty())
            {
                diff = *ms.rbegin() - *ms.begin();
            }
            
        }

        ans += r - l + 1;
    }

    return ans;
}

signed main()
{
    vector<int> arr = {84,84,25};
    int k = 61;

    cout<<countSubarrays(arr,k)<<endl;
    return 0;
}