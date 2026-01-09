#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n,s;
    cin>>n>>s;

    vector<int> weights(n), cost(n);
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    vector<int> pref_cost(n);
    for(int i=0;i<n;i++){
        if(i==0){
            pref_cost[i] = cost[i];
        }
        else{
            pref_cost[i] = pref_cost[i-1] + cost[i];
        }
    }

    int left = 0;
    int sum = 0;
    int ans = 0;
    for(int right = 0; right < n; right++){
        sum += weights[right];

        while(sum > s){
            sum -= weights[left];
            left++;
        }

        if(left == 0){
            ans = max(ans, pref_cost[right]);
        }
        else{
            ans = max(ans, pref_cost[right] - pref_cost[left-1]);
        }
    }

    cout << ans << "\n";

    return 0;
}
