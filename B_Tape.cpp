#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> seg(n);
    for (int i = 0; i < n; i++)
    {
        cin >> seg[i];
    }

    vector<int> gaps;
    for (int i = 1; i < n; i++)
    {
        int val = seg[i] - seg[i - 1] - 1; 
        gaps.push_back(val);
    }

    sort(gaps.rbegin(), gaps.rend()); 

    int total_length = seg[n - 1] - seg[0] + 1; 

    // k-1 largest gaps k both end points p will create and end tapes...
    for (int i = 0; i < min(k - 1, (int)gaps.size()); i++)
    {
        total_length -= gaps[i];
    }

    cout << total_length << endl;

    return 0;
}
