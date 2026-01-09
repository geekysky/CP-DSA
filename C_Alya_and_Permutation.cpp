#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;

        // Start with the initial pattern
        a.push_back(2);
        a.push_back(1);
        a.push_back(3);
        a.push_back(4);
        a.push_back(5);

        int even = 6;
        while (even <= n)
        {
            a.push_back(even);
            even += 2;
        }

        int odd = (n % 2 == 0) ? n - 1 : n;
        while (odd >= 7)
        {
            a.push_back(odd);
            odd -= 2;
        }

        // Calculate the value of k as per the operation rules
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 2 != 0)  // Odd position (1-based index)
                k = k & a[i];
            else                   // Even position (1-based index)
                k = k | a[i];
        }

        cout << k << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
