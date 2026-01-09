#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll var = arr[0];
        ll sum = 0;
        ll ans = 0;

        if (arr[0] == 0)
        {
            ans++;
        }

        for (int i = 1; i < n; i++){
            if (var < arr[i]){
                sum += var;
                var = arr[i];
                if (sum == var)
                {
                    ans++;
                }
            }

            else{
                sum += arr[i];
                if (sum == var)
                {
                    ans++;
                }
            }
        }

        cout << ans << "\n";
        
    }
    return 0;
}