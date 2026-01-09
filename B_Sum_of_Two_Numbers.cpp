#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2)
        {
            if (n % 10 == 9)
            {
                int up = 0, down = 0;
                string num1, num2;
                int temp = n; 
                
                while (temp)
                {
                    int dig = temp % 10;
                    int x = dig / 2;
                    int y = (dig + 1) / 2;

                    if (up == down)
                    {
                        num1 += ('0' + x);
                        num2 += ('0' + y);
                        if (y > x) down++;
                    }
                    else if (up < down)
                    {
                        num1 += ('0' + y);
                        num2 += ('0' + x);
                        if (y > x) up++;
                    }

                    temp /= 10;
                }

                reverse(num1.begin(), num1.end());
                reverse(num2.begin(), num2.end());

                // Remove leading zeros
                while (!num1.empty() && num1[0] == '0') num1.erase(num1.begin());
                while (!num2.empty() && num2[0] == '0') num2.erase(num2.begin());

                cout << num1 << " " << num2 << "\n";
            }
            else
            {
                cout << n / 2 << " " << (n + 1) / 2 << "\n";
            }
        }
        else
        {
            cout << n / 2 << " " << n / 2 << "\n";
        }
    }
    return 0;
}
