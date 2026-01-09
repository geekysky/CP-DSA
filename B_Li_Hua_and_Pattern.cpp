#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        // Let's find min number of different places with respect to the original matrix and rotated matrix
        int diff_places = 0;

        // Check the top half of the matrix and compare with the bottom half
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] != arr[(n - 1) - i][(n - 1) - j])
                {
                    diff_places++;
                }
            }
        }

        // If n is odd, check the middle row
        if (n % 2)
        {
            int row = n / 2;
            for (int i = 0; i < n / 2; i++)
            {
                if (arr[row][i] != arr[row][(n - 1) - i])
                {
                    diff_places++;
                }
            }
        }
        

        // Determine if it's possible to achieve the transformation with k changes
        if (diff_places <= k && ((k - diff_places) % 2 == 0 or n%2))
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
