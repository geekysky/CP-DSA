#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int a1(multiset<pair<int, int>, cmp> ms)
{
    if (ms.empty())
        return 0;
    int minR = LLONG_MAX, maxR = LLONG_MIN;
    int minC = LLONG_MAX, maxC = LLONG_MIN;
    for (auto &p : ms)
    {
        minR = min(minR, p.first);
        maxR = max(maxR, p.first);
        minC = min(minC, p.second);
        maxC = max(maxC, p.second);
    }

    int area = (maxC - minC + 1) * (maxR - minR + 1);
    if (ms.size() < area)
    {
        // we can accomodate the extreme monster within this new smaller rectangle
        return area;
    }
    else
    {
        // we either need to have a new row or a new column as the smaller rectangle is fully filled
        return min(((maxC - minC + 2) * (maxR - minR + 1)), ((maxC - minC + 1) * (maxR - minR + 2)));
    }
}

int a2(multiset<pair<int, int>> ms)
{
    if (ms.empty())
        return 0;
    int minR = LLONG_MAX, maxR = LLONG_MIN;
    int minC = LLONG_MAX, maxC = LLONG_MIN;
    for (auto &p : ms)
    {
        minR = min(minR, p.first);
        maxR = max(maxR, p.first);
        minC = min(minC, p.second);
        maxC = max(maxC, p.second);
    }

    int area = (maxC - minC + 1) * (maxR - minR + 1);
    if (ms.size() < area)
    {
        // we can accomodate the extreme monster within this new smaller rectangle
        return area;
    }
    else
    {
        // we either need to have a new row or a new column as the smaller rectangle is fully filled
        return min(((maxC - minC + 2) * (maxR - minR + 1)), ((maxC - minC + 1) * (maxR - minR + 2)));
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        
        sort(arr.begin(), arr.end());
        // Case 1: All points in same row or column
        bool all_same_row = true, all_same_col = true;
        for (int i = 1; i < n; i++)
        {
            if (arr[i].first != arr[0].first)
                all_same_row = false;
            if (arr[i].second != arr[0].second)
                all_same_col = false;
        }

        multiset<pair<int, int>, cmp> cols;
        multiset<pair<int, int>> rows;
        for (auto &p : arr)
        {
            cols.insert(p);
            rows.insert(p);
        }

        // if (all_same_row || all_same_col)
        // {
        //     // check span of row or col
        //     int row_span = arr[n - 1].first - arr[0].first + 1;
        //     int col_span = arr[n - 1].second - arr[0].second + 1;

        //     if (all_same_row)
        //     {
        //         cout << col_span << "\n";
        //     }
        //     else
        //     {
        //         cout << col_span << "\n";
        //     }
        //     continue;
        // }

        // Remove smallest column
        auto c1 = *cols.begin();
        cols.erase(cols.begin());
        int left_area = a1(cols);
        cols.insert(c1);

        // Remove largest column
        auto itc = prev(cols.end());
        auto c2 = *itc;
        cols.erase(itc);
        int right_area = a1(cols);
        cols.insert(c2);

        // Remove smallest row
        auto r1 = *rows.begin();
        rows.erase(rows.begin());
        int top_area = a2(rows);
        rows.insert(r1);

        // Remove largest row
        auto itr = prev(rows.end());
        auto r2 = *itr;
        rows.erase(itr);
        int bottom_area = a2(rows);
        rows.insert(r2);

        // check if all points lie in a single row or a single col and if n-1 points lie in a single row/col and onr pt lies elsewhere

        cout << min({left_area, right_area, top_area, bottom_area}) << "\n";
    }

    // int power(int base, int exp, int mod) {
    //     int result = 1;
    //     while (exp > 0) {
    //         if (exp % 2 == 1) {
    //             result = (result * base) % mod;
    //         }
    //         base = (base * base) % mod;
    //         exp /= 2;
    //     }
    //     return result;
    // }

    return 0;
}
