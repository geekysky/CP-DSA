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

        int mat[n][m];
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];

                maxi = max(maxi, mat[i][j]);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == maxi)
                {
                    cnt++;
                }
            }
        }

        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == maxi)
                {
                    temp++;
                }
            }

            row[i] = temp;
        }

        for (int j = 0; j < m; j++)
        {
            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                if (mat[i][j] == maxi)
                {
                    temp++;
                }
            }

            col[j] = temp;
        }
        // for(auto x:row){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:col){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        int dec = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {   
                int val=row[i]+col[j];
                if(mat[i][j]==maxi){
                    //intersection
                    val--;
                }

                if (val==cnt)
                {
                    // common row and column found
                    dec = maxi - 1;
                    break;
                }
            }

            if (dec != -1)
            {
                break;
            }
        }

        if (dec == -1)
        {
            cout << maxi << endl;
        }
        else
        {
            cout << dec << endl;
        }
    }
    return 0;
}