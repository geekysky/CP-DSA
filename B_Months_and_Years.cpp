#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool valid(string &checker, string &match) {
    int m = checker.size();
    for (int i = 0; i <= match.size() - m; i++) {
        if (match.substr(i, m) == checker) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Original strings
    string leap_non_leap = "312931303130313130313031312831303130313130313031";
    string non_leap_non_leap = "312831303130313130313031312831303130313130313031";
    string non_leap_leap = "312831303130313130313031312931303130313130313031";

    // New strings with three years
    string leap_nonleap_nonleap = 
        leap_non_leap + "312831303130313130313031"; // Leap -> Non-leap -> Non-leap

    string nonleap_nonleap_nonleap = 
        non_leap_non_leap + "312831303130313130313031"; // Non-leap -> Non-leap -> Non-leap

    string nonleap_leap_nonleap = 
        non_leap_leap + "312831303130313130313031"; // Non-leap -> Leap -> Non-leap

    string nonleap_nonleap_leap = 
        non_leap_non_leap + "312931303130313130313031"; // Non-leap -> Non-leap -> Leap

    // Create the checker string
    string checker = "";
    for (int i = 0; i < n; i++) {
        checker += to_string(arr[i]);
    }

    // Check against all strings
    if (valid(checker, leap_nonleap_nonleap)) {
        cout << "Yes" << '\n';
    } 
    else if (valid(checker, nonleap_nonleap_nonleap)) {
        cout << "Yes" << '\n';
    } 
    else if (valid(checker, nonleap_leap_nonleap)) {
        cout << "Yes" << '\n';
    } 
    else if (valid(checker, nonleap_nonleap_leap)) {
        cout << "Yes" << '\n';
    } 
    else {
        cout << "No" << '\n';
    }

    return 0;
}
