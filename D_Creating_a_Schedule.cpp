#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> classes(m);
        for (int i = 0; i < m; i++)
        {
            cin >> classes[i];
        }

        sort(classes.begin(), classes.end());

        // n/2 se zyada hone chahiye m bus ?
        // because n/2 distinct groups m distinct classrooms hone chahiye
        //  n<= m it suffices the above shortage problem
        int s = 0, e = m - 1;
        int cnt = 0;
        if (n % 2 == 0)
        {
            while (cnt != n)
            {
                int a = classes[s];
                int b = classes[e];

                for (int i = 1; i <= 3; i++)
                {
                    cout << a << " " << b << " ";
                }
                cout << endl;
                for (int i = 1; i <= 3; i++)
                {
                    cout << b << " " << a << " ";
                }
                cout<<endl;

                cnt += 2;
                s++;
                e--;
            }
        }
        else
        {
            // what if n is odd ? then extra sequence
            while (cnt != (n - 1))
            {
                int a = classes[s];
                int b = classes[e];

                for (int i = 1; i <= 3; i++)
                {
                    cout << a << " " << b << " ";
                }
                cout << endl;
                for (int i = 1; i <= 3; i++)
                {
                    cout << b << " " << a << " ";
                }
                cout<<endl;

                cnt += 2;
                s++;
                e--;
            }

            int a = classes[s];
            int b = classes[e];

            for (int i = 1; i <= 3; i++)
            {
                cout << a << " " << b << " ";
            }
            cout << endl;
        }
    }
    return 0;
}