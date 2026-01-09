#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{   
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int largest_odd_factor = 1;
        
        if (n == 1)
        {
            cout << "FastestFinger\n";
        }
        else if (n % 2 or n==2)
        {
            cout << "Ashishgup\n";
        }
        else
        {   
            int odd_factors=0;
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    if (i % 2)
                    {
                        largest_odd_factor = max(largest_odd_factor, i);
                        odd_factors++;
                    }
                    if ((n / i) % 2)
                    {
                        largest_odd_factor = max(largest_odd_factor, n / i);
                        odd_factors++;
                    }
                }
            }

            if (largest_odd_factor == 1)
            {
                cout << "FastestFinger\n";
            }
            else
            {   
                int temp=n;
                temp/=largest_odd_factor;
                if (temp == 2 and odd_factors==1)
                {   
                    //n=6 
                    cout << "FastestFinger\n";
                }
                else if(n%4==0)
                {
                    cout << "Ashishgup\n";
                }
                else
                {
                    //n=2*p
                    if(is_prime(n/2)){
                        //n is like 14,10...
                        cout << "FastestFinger\n";
                    }
                    else{
                        cout << "Ashishgup\n";
                    }
                }
            }
        }
    }
    return 0;
}