#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string num;
    cin >> num;

    string s;
    for (char ch : num)
    {
        int dig = ch - '0'; 

        if (dig == 4)
        {
            s += "322";
        }
        else if (dig == 6)
        {
            s += "53";
        }
        else if (dig == 8)
        {
            s += "7222";
        }
        else if (dig == 9)
        {
            s += "7332";
        }
        else if (dig == 2 || dig == 3 || dig == 7 || dig == 5)
        {
            s += ch;
        }
    }

    sort(s.rbegin(), s.rend());
    cout << s << "\n";

    return 0;
}
