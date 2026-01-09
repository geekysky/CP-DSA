#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

#define vi vector<ll>

#define vvi vector<vector<ll>>

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> A(n, vector<ll>(m));
    string s;
    cin >> s;

    // Input matrix
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    vi R(n), C(m);

    // Calculate row sums
    for (ll i = 0; i < n; i++)
    {
        ll sum = 0;
        for (ll j = 0; j < m; j++)
        {
            sum += A[i][j];
        }
        R[i] = sum;
    }

    // Calculate column sums
    for (ll j = 0; j < m; j++)
    {
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += A[i][j];
        }
        C[j] = sum;
    }

    ll x = 0, y = 0;
    ll cnt = 0;

    // Process directions
    while (cnt < n + m - 1)
    {
        if (s[cnt] == 'D')
        {
            A[x][y] = -R[x];
            R[x] += A[x][y];
            C[y] += A[x][y];
            x++;
        }
        else
        {
            A[x][y] = -C[y];
            R[x] += A[x][y];
            C[y] += A[x][y];
            y++;
        }
        cnt++;
    }

    // Output updated matrix
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
