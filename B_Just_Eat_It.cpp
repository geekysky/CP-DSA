#include <bits/stdc++.h>
using namespace std;
#define int long long int

pair<long long, int> maxSubarraySum(vector<int> &arr)
{
    int n = arr.size();

    // Handle base case
    if (n <= 1)
        return {0, 0};

    // Calculate prefix sums
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    // Calculate total sum
    long long totalSum = prefixSum[n];

    // Find maximum subarray sum using Kadane's algorithm
    long long maxSoFar = INT_MIN;
    long long currMax = 0;
    int len = 0;
    int currLen = 0;

    for (int i = 0; i < n; i++)
    {
        currMax += arr[i];
        currLen++;

        if (currMax > maxSoFar && currLen < n)
        {
            maxSoFar = currMax;
            len = currLen;
        }

        if (currMax < 0)
        {
            currMax = 0;
            currLen = 0;
        }
    }

    // Handle case when all elements are negative
    if (maxSoFar == INT_MIN)
    {
        maxSoFar = arr[0];
        len = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > maxSoFar)
            {
                maxSoFar = arr[i];
                len = 1;
            }
        }
    }

    // Find maximum sum of suffix
    long long maxSuffix = INT_MIN;
    int suffixLen = 0;
    for (int i = 1; i < n; i++)
    {
        long long suffixSum = totalSum - prefixSum[i];
        if (suffixSum > maxSuffix)
        {
            maxSuffix = suffixSum;
            suffixLen = n - i;
        }
    }

    // Find maximum sum of prefix
    long long maxPrefix = INT_MIN;
    int prefixLen = 0;
    for (int i = n - 1; i > 0; i--)
    {
        long long prefixSum_i = prefixSum[i];
        if (prefixSum_i > maxPrefix)
        {
            maxPrefix = prefixSum_i;
            prefixLen = i;
        }
    }

    // Return maximum of all cases (excluding full array)
    if (maxSuffix > maxSoFar && maxSuffix > maxPrefix)
    {
        return {maxSuffix, suffixLen};
    }
    else if (maxPrefix > maxSoFar && maxPrefix > maxSuffix)
    {
        return {maxPrefix, prefixLen};
    }
    return {maxSoFar, len};
    
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
        int total = 0;

        vector<int> res;
        int neg = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total += arr[i];
        }

        // pair<int, int> ans = maxSubarraySum(arr);
        // if (ans.first < total and ans.second != n)
        // {
        //     cout << "YES" << endl;
        // }
        // else
        // {
        //     cout << "NO" << endl;
        // }

        if(total>0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}