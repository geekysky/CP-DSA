#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        string s;
        cin >> s;
        
        int n = s.size();
        
        // Count initially used characters
        for (char c : s) {
            if (c == '0') a--;
            if (c == '1') b--;
        }
        
        // Count question marks
        int question_marks = count(s.begin(), s.end(), '?');
        
        // First check if it's potentially possible
        if (a < 0 || b < 0 || a + b != question_marks) {
            cout << "-1\n";
            continue;
        }
        
        // Check palindrome constraints and fill in known values
        bool possible = true;
        for (int i = 0; i < n/2; i++) {
            if (s[i] != '?' && s[n-1-i] != '?' && s[i] != s[n-1-i]) {
                possible = false;
                break;
            }
            
            // Fill in known values
            if (s[i] != '?' && s[n-1-i] == '?') {
                s[n-1-i] = s[i];
                if (s[i] == '0') a--;
                else b--;
            } else if (s[i] == '?' && s[n-1-i] != '?') {
                s[i] = s[n-1-i];
                if (s[n-1-i] == '0') a--;
                else b--;
            }
        }
        
        if (!possible || a < 0 || b < 0) {
            cout << "-1\n";
            continue;
        }
        
        // Handle middle character for odd length strings
        if (n % 2 == 1 && s[n/2] == '?') {
            if (a % 2 == 1) {
                s[n/2] = '0';
                a--;
            } else if (b % 2 == 1) {
                s[n/2] = '1';
                b--;
            } else {
                // Either can be used
                if (a > 0) {
                    s[n/2] = '0';
                    a--;
                } else {
                    s[n/2] = '1';
                    b--;
                }
            }
        }
        
        // Check if remaining characters can form pairs
        if (a % 2 != 0 || b % 2 != 0) {
            cout << "-1\n";
            continue;
        }
        
        // Fill in remaining question marks
        for (int i = 0; i < n/2; i++) {
            if (s[i] == '?' && s[n-1-i] == '?') {
                if (a >= 2) {
                    s[i] = s[n-1-i] = '0';
                    a -= 2;
                } else if (b >= 2) {
                    s[i] = s[n-1-i] = '1';
                    b -= 2;
                }
            }
        }
        
        // Final verification
        if (a != 0 || b != 0) {
            cout << "-1\n";
            continue;
        }
        
        cout << s << "\n";
    }
    return 0;
}