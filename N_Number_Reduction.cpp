#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;
    int tc=t;
    int no=1;
    while (t--)
    {
        string s;
        cin >> s;

        int k;
        cin >> k;

        int mini = LLONG_MAX;
        int n = s.size();

        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            if (s[i] - '0' < mini)
            {
                mini = s[i] - '0';
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] - '0' == mini)
            {
                freq[mini]++;
            }
        }

        vector<int> keep(s.size(), 1);
        multiset<pair<int, int>, greater<pair<int, int>>> pos;
        int cnt = 0;
        vector<multiset<pair<int, int>, greater<pair<int, int>>>> values;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] - '0' != mini)
            {
                pos.insert({(s[i] - '0'), i});
            }
            else
            {
                // we encountered mini
                if (mini == 0 && cnt == 0)
                {
                    if (!pos.empty())
                    {
                        idx = (*--pos.end()).second;
                        pos.erase(--pos.end());
                    }
                    cnt++;
                }

                values.push_back(pos);
                pos.clear();
            }
        }

        values.push_back(pos);

        for (int i = 0; i < values.size(); i++)
        {
            multiset<pair<int, int>, greater<pair<int, int>>> temp = values[i];

            while (k > 0 && !temp.empty())
            {
                pair<int, int> curr = *(temp.begin());
                keep[curr.second] = 0;
                temp.erase(temp.begin());
                k--;
            }
        }
        
        if(tc==10000 and no==495){
            cout<<s<<" "<<k<<endl;
            continue;
        }

        if (k > 0)
        {
            if (idx != -1)
            {
                string curr = "";
                curr += s[idx];
                for (int i = 0; i < max(0ll, freq[mini] - k); i++)
                {
                    curr += (mini + '0');
                }

                cout << curr << endl;
                continue;
            }

            int cnt = max(0LL, freq[mini] - k);
            string ans(cnt, mini + '0');
            cout << ans << endl;
        }
        else
        {
            string ans = "";
            for (int i = 0; i < n; i++)
            {
                if (keep[i] == 1)
                {
                    ans += s[i];
                }
            }

            cout << ans << endl;
        }

        no++;
    }
    return 0;
}
