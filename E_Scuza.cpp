#include<bits/stdc++.h>
using namespace std;
#define int long long int 

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n, q;
        cin>>n>>q;
        
        vector<int> prefix_stairs(n), pref_highest_stair(n);
        for(int i = 0; i < n; i++){
            int ele;
            cin>>ele;

            if(i == 0){
                prefix_stairs[i] = ele;
                pref_highest_stair[i] = ele;
            }
            else{
                prefix_stairs[i] = prefix_stairs[i-1] + ele;
                pref_highest_stair[i] = max(pref_highest_stair[i-1], ele);
            }
        }

        for(int i = 0; i < q; i++){
            int ki;
            cin>>ki;

            if(ki == 0){
                cout << 0 << " ";
                continue; // No need to perform further operations
            }
            
            auto it = upper_bound(pref_highest_stair.begin(), pref_highest_stair.end(), ki);

            if(it == pref_highest_stair.begin()){
                cout << 0 << " "; // No element is less than or equal to ki
            }
            else{
                it--; // Move to the largest element less than or equal to ki
                cout << prefix_stairs[it - pref_highest_stair.begin()] << " ";
            }
        }

        cout << "\n";
    }
    return 0;
}
