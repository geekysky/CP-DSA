#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    bool found=false;
    for(int i=0;i<n-2;i++){
        if(arr[i]+arr[i+1]>arr[i+2]){
            found=true;
            break;
        }
    }

    if(found)
    cout<<"YES"<<"\n";

    else
    cout<<"NO"<<"\n";

    return 0;
}