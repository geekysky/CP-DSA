#include <iostream>
#include <string>
using namespace std;

void solve() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Length of the binary string

        string current_string = ""; // To store the constructed password
        
        // Construct the password character by character
        for (int i = 0; i < n; ++i) {
            // Try to append '0' to the current string
            string guess_0 = current_string + '0';
            cout << "? " << guess_0 << endl;
            int response_0;
            cin >> response_0;
            
            // Try to append '1' to the current string
            string guess_1 = current_string + '1';
            cout << "? " << guess_1 << endl;
            int response_1;
            cin >> response_1;
            
            // Determine which character is correct and append it to current_string
            if (response_0 == 1) {
                current_string += '0';
            } else {
                current_string += '1';
            }
        }
        
        // Output the final constructed password
        cout << "! " << current_string << endl;
    }
}

int main() {
    solve();
    return 0;
}
