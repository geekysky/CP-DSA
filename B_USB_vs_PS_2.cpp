#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> usb, ps2;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        string s;
        cin >> x >> s;
        if (s == "USB")
        {
            usb.push_back(x);
        }
        else
        {
            ps2.push_back(x);
        }
    }

    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());
    // int total=min(a, (int)usb.size())+min(b, (int)ps2.size());
    // int rem1=max(0ll,usb.size()-min(a, (int)usb.size()));
    // int rem2=max(0ll,ps2.size()-min(b, (int)ps2.size()));
    // //total+=min(c, rem1+rem2);

    // we want to fulfill total places with min cost as possible
    vector<int> rem;
    int cost = 0, devices = 0;

    int i = 0, j = 0;

    for (i = 0; i < min(a, (int)usb.size()); i++)
    {
        cost += usb[i];
        devices++;
    }
    for (j = 0; j < min(b, (int)ps2.size()); j++)
    {
        cost += ps2[j];
        devices++;
    }

    for (int k = i; k < usb.size(); k++)
    {
        rem.push_back(usb[k]);
    }
    for (int k = j; k < ps2.size(); k++)
    {
        rem.push_back(ps2[k]);
    }

    sort(rem.begin(), rem.end());
    for (int k = 0; k < min(c, (int)rem.size()); k++)
    {
        cost += rem[k];
        devices++;
    }

    cout << devices << " " << cost << endl;
    return 0;
}