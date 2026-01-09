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
        
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])!=5 and abs(arr[i]-arr[i+1])!=7){
                flag=false;
                break;
            }
        }

        if(flag){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}