#include <bits/stdc++.h>
using namespace std;
#define int long long int

int maxBeauty(const string &s, char target, int k)
{
    int n = s.size();
    int start = 0, max_len = 0, current_changes = 0;

    for (int end = 0; end < n; ++end)
    {
        if (s[end] != target)
        {
            ++current_changes;
        }
        while (current_changes > k)
        {
            if (s[start] != target)
            {
                --current_changes;
            }
            ++start;
        }
        max_len = max(max_len, end - start + 1);
    }

    return max_len;
}

signed main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int result = max(maxBeauty(s, 'a', k), maxBeauty(s, 'b', k));

    cout << result << endl;

    return 0;
}
