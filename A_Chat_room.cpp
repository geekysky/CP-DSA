#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;

    bool h_found = false, e_after_h = false, l_after_e = false, l2_after_l1 = false, o_after_l2 = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'h' && !h_found) {
            h_found = true;
        }
        else if (s[i] == 'e' && h_found && !e_after_h) {
            e_after_h = true;
        }
        else if (s[i] == 'l' && e_after_h && !l_after_e) {
            l_after_e = true;
        }
        else if (s[i] == 'l' && l_after_e && !l2_after_l1) {
            l2_after_l1 = true;
        }
        else if (s[i] == 'o' && l2_after_l1) {
            o_after_l2 = true;
        }
    }

    if (h_found && e_after_h && l_after_e && l2_after_l1 && o_after_l2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
