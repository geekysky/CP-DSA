#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool is_prime(int x)
{
    if (x <= 1) return false; // FIX: 0 and 1 are not prime
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Function to create palindrome from a root number
// e.g., createPalindrome(12, false) -> 1221 (even length)
// e.g., createPalindrome(12, true)  -> 121  (odd length)
int createPalindrome(int input, bool isOdd)
{
    int n = input;
    int palin = input;

    if (isOdd)
        n /= 10; // Ignore the last digit for the middle of odd palindrome

    while (n > 0)
    {
        palin = palin * 10 + (n % 10);
        n /= 10;
    }
    return palin;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    vector<int> pal_primes;

    // Generate palindromes
    // We iterate 1 to 100,000 to cover palindromes up to 9-10 digits
    // 10000 -> generates 100000001 (9 digits)
    for (int i = 1; i <= 100000; i++) 
    {
        // Generate Odd length palindromes (e.g., 121)
        int p1 = createPalindrome(i, true);
        if (p1 >= a && p1 <= b && is_prime(p1))
            pal_primes.push_back(p1);

        // Generate Even length palindromes (e.g., 1221)
        int p2 = createPalindrome(i, false);
        if (p2 >= a && p2 <= b && is_prime(p2))
            pal_primes.push_back(p2);
    }
    
    // 0 is handled by logic, but manual check for '0' palindrome just in case 
    // (though '0' is not prime so it doesn't matter for the count)

    // Sort is needed because even/odd generation might not be perfectly sequential
    sort(pal_primes.begin(), pal_primes.end());
    
    // Remove duplicates if any (though this logic usually doesn't produce them)
    pal_primes.erase(unique(pal_primes.begin(), pal_primes.end()), pal_primes.end());

    // Because we filtered >= a and <= b during generation, we can just print size
    // But to be safe with your original logic's bounds:
    
    // Since we already filtered inside the loop:
    cout << pal_primes.size() << endl;

    return 0;
}