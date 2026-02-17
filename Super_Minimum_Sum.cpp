#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> getNSE(vector<int> &A)
{
    int n = A.size();
    vector<int> nse(n, n); // Default to N (right boundary)
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && A[st.top()] > A[i])
        {
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nse;
}

vector<int> getPSE(vector<int> &A)
{
    int n = A.size();
    vector<int> pse(n, -1); // Default to -1 (left boundary)
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && A[st.top()] > A[i])
        {
            pse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return pse;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> PSE = getPSE(arr);
        vector<int> NSE = getNSE(arr);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int left = i - PSE[i];

            int right = NSE[i] - i;

            ans += (left * right * arr[i]);
        }

        cout << ans << endl;
    }

    return 0;
}