#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n,k;
    cin>>n>>k;

    int arr[n];
    int targets[k];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<k;i++){
        cin>>targets[i];
    }

    for(int i=0;i<k;i++){
        int target=targets[i];

        int lb=0,ub=n-1;
        bool found=false;

        while(lb<=ub){
            int mid=(lb+ub)/2;

            if(arr[mid]==target){
                found=true;
                break;
            }
            else{
                if(arr[mid]>target){
                    ub=mid-1;
                }
                else{
                    lb=mid+1;
                }
            }
        }

        if(!found){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
        
    }

    return 0;
}