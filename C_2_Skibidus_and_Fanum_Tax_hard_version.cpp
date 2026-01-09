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

        vector<int> a(n), b(m), temp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(b.begin(), b.end());
        temp.push_back(min(b[0] - a[0], a[0]));

        bool possible = true;
        for (int i = 1; i < n; i++)
        {
            auto it = lower_bound(b.begin(), b.end(), temp.back() + a[i]);

            if (it != b.end())
            {
                int ele = min(*it - a[i], a[i]);

                if (*it-a[i] < temp.back() and a[i] < temp.back())
                {
                    possible = false;
                    break;
                }
                else
                {
                    if(*it - a[i] >= temp.back() and a[i]>=temp.back()){
                        temp.push_back(ele);
                    }
                    else if(*it - a[i] >= temp.back() and a[i]<temp.back()){
                        temp.push_back(*it - a[i]);
                    }
                    else{
                        if(a[i]>=temp.back()){
                            temp.push_back(a[i]);
                        }
                    }
                }
            }
            else
            {
                if (a[i] < temp.back())
                {
                    possible = false;
                    break;
                }
                else
                {
                    temp.push_back(a[i]);
                }
            }
        }

        if (possible)
        {
            // for(int i=1;i<temp.size();i++){
            //     if(temp[i]<temp[i-1]){
            //         possible=false;
            //         break;
            //     }
            // }

            // if(possible){
            //     cout<<"YES"<<"\n";
            // }
            // else{
            //     cout<<"NO"<<"\n";
            // }
            cout<<"YES"<<endl;
        }
        else
        {
            cout << "NO" << "\n";
        }

        
    }
}