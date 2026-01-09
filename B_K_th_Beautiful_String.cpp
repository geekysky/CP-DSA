#include <bits/stdc++.h>
using namespace std;
#define int long long int 

bool cmp(pair<int, int> &segment, int k)
{
    // to advance the iterator
    // it stops at the position where condition becomes false

    return segment.second < k;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> ranges;

        int start = 1;
        int end = 1;

        ranges.push_back({1, 1});
        for (int i = 2; i <= n - 1; i++)
        {
            start = end + 1;
            end = start + i - 1;

            ranges.push_back({start, end});
            // 2 - {2,3} , 3 - {4,6}
        }

        // ranges is sorted
        auto it = lower_bound(ranges.begin(), ranges.end(), k, cmp);

        //cout << it->first << " " << it->second << endl;

        int segment_no = it - ranges.begin() + 1;

        //construct a string first of all aa's 
        string ans=string(n,'a');

        //cout<<ans<<endl;

        //ans[n-1]='b';
        ans[n-1-segment_no]='b';

        //cout<<ans<<endl;

        int diff=k-it->first;
        ans[n-1-diff]='b';

        cout<<ans<<"\n";



    }

    return 0;
}