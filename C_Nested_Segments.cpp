#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    if (a.first.first == b.first.first)
        return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

struct customComp
{
    bool operator()(const pair<int, int> &a,
                    const pair<int, int> &b) const
    {
        return a.first > b.first;
    }
};

signed main()
{

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> arr;

    // r and index no
    multiset<pair<int, int>, customComp> ms;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        arr.push_back({{l, r}, i + 1});
    }

    sort(arr.begin(), arr.end(), cmp);
    int x = -1, y = -1;

    for (int i = 0; i < n; i++)
    {

        // if the current is the enclosed/i th pair...find j
        pair<pair<int, int>, int> curr = arr[i];

        if (!ms.empty())
        {
            pair<int, int> largest = *ms.begin();

            if (largest.first >= curr.first.second)
            {
                x = curr.second;
                y = largest.second;
            }
        }

        // current r and index no.
        ms.insert({curr.first.second, curr.second});

        if (x != -1)
        {
            break;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}