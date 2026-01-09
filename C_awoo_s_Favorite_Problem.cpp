#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;

    // Condition 1: Check if character counts are the same.
    std::string s_sorted = s, t_sorted = t;
    sort(s_sorted.begin(), s_sorted.end());
    sort(t_sorted.begin(), t_sorted.end());
    if (s_sorted != t_sorted)
    {
        std::cout << "NO\n";
        return;
    }

    // Condition 2: Check relative order of 'a's and 'c's.
    // If we remove all 'b's, the remaining strings must be identical.
    std::string s_ac, t_ac;
    std::vector<int> s_a_indices, t_a_indices;
    std::vector<int> s_c_indices, t_c_indices;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] != 'b')
        {
            s_ac += s[i];
        }
        if (t[i] != 'b')
        {
            t_ac += t[i];
        }
        // Store indices for condition 3
        if (s[i] == 'a')
            s_a_indices.push_back(i);
        if (s[i] == 'c')
            s_c_indices.push_back(i);
        if (t[i] == 'a')
            t_a_indices.push_back(i);
        if (t[i] == 'c')
            t_c_indices.push_back(i);
    }

    if (s_ac != t_ac)
    {
        std::cout << "NO\n";
        return;
    }

    // Condition 3: Check directional movement constraints.
    // 'a' can only move right.
    for (size_t i = 0; i < s_a_indices.size(); ++i)
    {
        if (s_a_indices[i] > t_a_indices[i])
        {
            std::cout << "NO\n";
            return;
        }
    }

    // 'c' can only move left.
    for (size_t i = 0; i < s_c_indices.size(); ++i)
    {
        if (s_c_indices[i] < t_c_indices[i])
        {
            std::cout << "NO\n";
            return;
        }
    }

    // If all conditions are met, it's possible.
    std::cout << "YES\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int q;
    std::cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}