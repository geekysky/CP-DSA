#include <bits/stdc++.h>
using namespace std;
#define int long long int

map<int, int> ones;

void f(string s)
{
    string temp = "";
    for (int i = 0; i < s.size() - 1; i++)
    {
        temp += s[i];
    }

    int num;
    if (temp == "")
    {
        num = 0;
    }
    else
    {
        num = stoi(temp);
    }

    if (num % 2)
    {
        ones[-1]++;
    }
    else
    {
        ones[-2]++;
    }
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            if (s.back() == '1' or s.back() == '2' or s.back() == '4' or s.back() == '8')
            {
                f(s);
            }
            else if (s.back() == '3' or s.back()=='9')
            {
                // add 9
                int num = stoi(s);
                num += 9;

                string temp = to_string(num);
                f(temp);
            }
            else if (s.back() == '6')
            {
                // add 6
                int num = stoi(s);
                num += 6;

                string temp = to_string(num);
                f(temp);
            }
            else if (s.back() == '5')
            {
                int num = stoi(s);
                num += 5;

                ones[num]++;
            }
            else if (s.back() == '7')
            {
                // add 7
                int num = stoi(s);
                num += 7;

                string temp = to_string(num);
                f(temp);
            }
            else
            {
                int num = stoi(s);
                ones[num]++;
            }
        }

        if (ones.size() > 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }

        ones.clear();
    }

    return 0;
}