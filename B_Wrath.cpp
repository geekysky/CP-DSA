#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    multiset<int> alive;
    vector<int> diff(n);
    for (int i = 0; i < n; i++)
    {
        diff[i] = (i + 1) - arr[i];
    }

    alive.insert(1);
    for (int i = 1; i < n; i++)
    {
        // Create a copy to safely iterate
        multiset<int> temp = alive;

        // Safely remove elements
        for (auto it = temp.begin(); it != temp.end();)
        {
            if (*it >= diff[i])
            {
                alive.erase(alive.find(*it));
                it = temp.erase(it);
            }
            else
            {
                ++it;
            }
        }

        // cout << alive.size() << " ";
        alive.insert(i + 1);
    }

    cout << alive.size() << "\n";

    return 0;
}