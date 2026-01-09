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

    if(n==1 or n==2){
        cout<<0<<"\n";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    else{
        cout<<(n-1)/2<<"\n";
        int s=0,e=n-1;

        while(s<=e){
            if(s==e)
            cout<<arr[s]<<" ";

            else
            cout<<arr[e]<<" "<<arr[s]<<" ";

            s++;
            e--;
        }

        cout<<"\n";
    }
    return 0;
}