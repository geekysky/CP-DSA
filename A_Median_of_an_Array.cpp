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

        int med_ind=ceil((double)n/2);

        int min_ops=0;
        sort(arr,arr+n);
        for(int i=med_ind-1;i<n;i++){
            if(arr[i]==arr[med_ind-1])
            min_ops++;
        }

        cout<<min_ops<<"\n";
    }
    return 0;
}