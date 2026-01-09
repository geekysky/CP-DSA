#include <bits/stdc++.h>
using namespace std;
#define int long long int

int factorial(int n)
{
    int res = 1;
    for (int i = n; i >= 1; i--)
    {
        res *= i;
    }

    return res;
}

int permutation(int n, int a, int b)
{
    int num = factorial(n);
    int den = factorial(a) * factorial(b);

    // this can never be a decimal value
    return num / den;
}

signed main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '+')
            x1++;
        else if (s1[i] == '-')
            y1++;
        if (s2[i] == '+')
            x2++;
        else if (s2[i] == '-')
            y2++;
    }

    if (x1 == x2 and y1 == y2)
    {
        cout << setprecision(12) << fixed << 1.0 << "\n";
    }
    else if (x2 > x1 or y2 > y1)
    {
        cout << setprecision(12) << fixed << 0.0 << "\n";
    }
    else
    {
        int diff1 = x1 - x2;
        int diff2 = y1 - y2;
        int diff = diff1 + diff2;

        int denominator = pow(2, diff);
        int numerator = permutation(diff, diff1, diff2);
        // cout<<diff<<" "<<diff1<<" "<<diff2<<"\n";
        // cout<<numerator<<" "<<denominator<<"\n";

        cout<<setprecision(12)<<fixed<<(double)numerator/denominator<<"\n";
    }

    return 0;
}