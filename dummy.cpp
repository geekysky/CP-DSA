#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int

int getInversions(int *arr, int n)
{
    int cnt = 0;
    ordered_multiset<int> ms;
    for (int i = n - 1; i >= 0; i--)
    {
        if (ms.empty())
        {
            ms.insert(arr[i]);
        }
        else
        {
            cnt += ms.order_of_key(arr[i]);
            ms.insert(arr[i]);
        }
    }

    return cnt;
}

signed main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();

    int ans = getInversions(arr.data(), n);
    cout << ans << "\n";
}