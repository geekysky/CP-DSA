#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define small (s[0] >= 'a' and s[0] <= 'z')
#define upper (s[0] >= 'A' and s[0] <= 'Z')
int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int rest_all = 0;

    if (n == 1)
    {
        if (s[0] >= 'a' and s[0] <= 'z')
        {
            s[0] = (s[0] - 'a') + 'A';
        }
        else
        {
            s[0] = (s[0] - 'A') + 'a';
        }
    }
    
    else{
    for (int i = 1; i < n; i++)
    {

        if (s[i] >= 'A' and s[i] <= 'Z')
        {
            rest_all++;
        }
    }

    if (rest_all == n - 1)
    {
        if (s[0] >= 'a' and s[0] <= 'z')
        {
            s[0] = (s[0] - 'a') + 'A';
        }
        else if(upper){
            s[0] = (s[0] - 'A') + 'a';
        }

        for (int i = 1; i < n; i++)
        {
            s[i] = (s[i] - 'A') + 'a';
        }
    }
    }

    cout << s << "\n";
    return 0;
}