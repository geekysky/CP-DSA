#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int arr[3];
        for(int i=0;i<3;i++){
            cin>>arr[i];
        }

        sort(arr,arr+3);

        cout<<abs(arr[0]-arr[1])+abs(arr[2]-arr[1])<<"\n";
    }
    return 0;
}