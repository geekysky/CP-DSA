#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;

    int x = 0;

    while (n--)
    {
        string s;
        cin >> s;

        if(s[0]=='+' or s[2]=='+'){
            x++;
        }
        else{
            x--;
        }
    }

    cout<<x<<"\n";

    return 0;
}