#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);
        int tot_grannies=1;
        for(int i=n-1;i>=0;i--){
            if(arr[i]<= i+1){
                tot_grannies=i+2;
                break;
            }
        }

        cout<<tot_grannies<<"\n";
    }
    return 0;
}