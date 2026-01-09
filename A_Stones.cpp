#include<bits/stdc++.h>
using namespace std;
#define ll long long

int first_type(int a, int b) {
    int pairs = min(a, b / 2);
    return pairs * 3; // each pair contributes a + 2*b = 3
}

int second_type(int b, int c) {
    int pairs = min(b, c / 2);
    return pairs * 3; // each pair contributes b + 2*c = 3
}

int one_then_two(int a, int b, int c) {
    int ans = 0;
    int pairs = min(a, b / 2);
    ans += pairs * 3; // a, b pair contribution
    b -= pairs * 2;   // reducing b as those are used in pairs with a
    
    pairs = min(b, c / 2);
    ans += pairs * 3; // b, c pair contribution
    
    return ans;
}

int two_then_one(int a, int b, int c) {
    int ans = 0;
    int pairs = min(b, c / 2);
    ans += pairs * 3; // b, c pair contribution
    b -= pairs;       // reducing b as those are used in pairs with c
    
    pairs = min(a, b / 2);
    ans += pairs * 3; // a, b pair contribution
    
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int only1 = first_type(a, b);
        int only2 = second_type(b, c);
        int ek_do = one_then_two(a, b, c);
        int do_ek = two_then_one(a, b, c);

        cout << max({only1, only2, ek_do, do_ek}) << "\n";
    }
    return 0;
}
