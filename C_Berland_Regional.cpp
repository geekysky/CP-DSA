#include <bits/stdc++.h>
using namespace std;
#define int long long int

int largestvalueincnt(map<int, int> &cnt)
{
    int largest = 0;
    for (auto i : cnt)
    {
        largest = max(largest, i.second);
    }
    return largest;
}

signed main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> arr(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            cnt[arr[i].first]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].second;
        }

        int largest = largestvalueincnt(cnt);

        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i].first].push_back(arr[i].second);
        }

        for (auto &i : mp)
        {
            sort(i.second.begin(), i.second.end(), greater<int>());
        }

        for (auto &it : mp)
        {
            for (int i = 1; i < it.second.size(); i++)
            {
                it.second[i] += it.second[i - 1];
            }
        }

        vector<vector<int>> values;
        for (auto it : mp)
        {
            values.push_back(it.second);
        }
        vector<int> ans(n, 0);
        for(auto i:values){
            for(int j=1;j<=i.size();j++){
                int rem = i.size()%j;
                int sum = 0;
                if(rem==0){
                    sum = i.back();
                }else{
                    sum = i[i.size()-rem-1];
                }
                ans[j-1] += sum;                        
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}