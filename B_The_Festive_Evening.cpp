#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<pair<int, int>> arr(26);
    for (int i = 0; i < 26; i++)
    {
        arr[i].first = -1;
        arr[i].second = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[s[i] - 'A'].first == -1)
        {
            arr[s[i] - 'A'].first = i;
        }

        arr[s[i] - 'A'].second = i;
    }

    int guards_required = 0;
    bool unguarded = false;

    for (int i = 0; i < n; i++)
    {
        if (i == arr[s[i] - 'A'].first)
        {
            guards_required++;
        }

        if (guards_required > k)
        {
            unguarded = true;
            break;
        }

        if (i == arr[s[i] - 'A'].second)
        {
            // a guard gets free
            guards_required--;
        }
    }

    if (unguarded)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }

    return 0;
}