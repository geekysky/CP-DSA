#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

signed main()
{
    int n;
    cin >> n;

    if (n == 3)
    {
        cout << 1 << endl;
        cout << 3 << endl;
        return 0;
    }
    if (n == 4)
    {
        cout << 2 << endl;
        cout << 2 << " " << 2 << endl;
        return 0;
    }
    if (n == 5)
    {
        cout << 1 << endl;
        cout << 5 << endl;
        return 0;
    }
    if (n == 6)
    {
        cout << 2 << endl;
        cout << 3 << " " << 3 << endl;
        return 0;
    }
    if (n == 7)
    {
        cout << 1 << endl;
        cout << 7 << endl;
        return 0;
    }

    // at most 3 prime nos are needed to sum up to n
    int val = n - 2;
    int x, y, z;
    while (true)
    {
        if (is_prime(val))
        {
            // largest prime no <= n-4 has been found
            z = val;
            break;
        }

        val--;
    }

    // now two prime nos such that x + y = n-val ;
    // this n-val is really small as val is pretty close to n as adjacent primes dont have much difference ~at most 300 nums ?
    int sum = n - z;
    if (is_prime(sum))
    {
        cout << 2 << endl;
        cout << sum << " " << z << endl;
        return 0;
    }

    for (int i = 2; i <= sum / 2; i++)
    {
        if ((is_prime(i) && is_prime(sum - i)))
        {
            x = i;
            y = sum - i;
            break;
        }
    }

    cout << 3 << endl;
    cout << x << " " << y << " " << z << endl;
    return 0;
}