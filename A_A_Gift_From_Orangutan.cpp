#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(),arr.end());

        if(n==1){
            cout<<0<<"\n";
        }

        else{
            cout<<(n-1)*(arr[n-1]-arr[0])<<"\n";
        }
    }
    return 0;
}