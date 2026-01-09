#include<bits/stdc++.h>
using namespace std;

#define ll long long

string convert_to_words(int n) {
    // Arrays to store words for single digits and tens
    string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                     "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    // If the number is less than 20, use the ones array
    if (n < 20) {
        return ones[n];
    }
    // If the number is 20 or more
    else {
        int ten_val = n / 10;
        int one_val = n % 10;
        
        // If the number is a multiple of 10
        if (one_val == 0) {
            return tens[ten_val];
        }
        // Otherwise, combine tens and ones
        else {
            return tens[ten_val] + "-" + ones[one_val];
        }
    }
}

int main() {
    int n;
    cin >> n;

    // Ensure the input is within the specified range 0<=n<=99
    if (n < 0 || n > 99) {
        cout << "Input out of range" << "\n";
    } else {
        cout << convert_to_words(n) << "\n";
    }

    return 0;
}
