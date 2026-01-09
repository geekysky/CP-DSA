#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(2*n);
        int o=0, z=0;
        for(int i=0; i<(2*n); i++){
            cin>>arr[i];

            if(arr[i]==0){
                z++;
            }
            else{
                o++;
            }
        }

        int max_on = min(o, z);
        int min_on = (o % 2 == 1 && z % 2 == 1) ? 1 : 0;

        cout << min_on << " " << max_on << "\n";
    }
    return 0;
}
