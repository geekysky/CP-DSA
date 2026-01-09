#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool contain_digits(int x, int y)
{
    vector<int> one, two;

    while (x)
    {
        int dig = x % 10;
        one.push_back(dig);
        x /= 10;
    }

    while (y)
    {
        int dig = y % 10;
        two.push_back(dig);
        y /= 10;
    }

    for (int i = 0; i < two.size(); i++)
    {
        for (int j = 0; j < one.size(); j++)
        {
            if (two[i] == one[j])
            {
                return true;
            }
        }
    }

    return false;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        vector<int> one;
        while (x)
        {
            int dig = x % 10;
            one.push_back(dig);
            x /= 10;
        }

        sort(one.begin(), one.end());
        for (int i = 0; i < one.size(); i++)
        {
            cout << one[i] << endl;
            break;
        }
    }
    return 0;
}