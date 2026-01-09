#include<bits/stdc++.h>
using namespace std;
#define int long long int

int nearest_power_of_two(int num){
    int base=2;
    int res=1;

    while(res<num){
        res*=2;
    }

    return res;
}
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        //make table of 2 
        cout<<n<<"\n";
        
        for(int i=0;i<n;i++){
            cout<<(i+1)<<" "<<nearest_power_of_two(arr[i]) - arr[i]<<"\n";
        }

    }
    return 0;
}