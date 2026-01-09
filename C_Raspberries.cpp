#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        int arr[n];
        int even=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];

            if(arr[i]%2==0){
                even++;
            }
        }

        int ans = INT_MAX;

        if (k == 4 ) {
            if (even == 0) ans = 2;
            else if (even == 1) ans = 1;
            else ans = 0;
        }
 
 
        for (int i = 0; i < n; ++i)
        {
            /* code */
            int s = arr[i] % k;
            if (s == 0) ans = 0;
            ans = min(ans, k - s);
        }
 
 
 
 
 
        cout << (ans) << endl;
    }
    return 0;
}