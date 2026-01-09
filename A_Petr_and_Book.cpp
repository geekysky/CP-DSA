#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n;
    cin>>n;

    int arr[7];
    for(int i=0;i<7;i++){
        cin>>arr[i];
    }

    int rem=n;
    int ind=0;
    int ans;
    while(rem>0){
        rem-=arr[ind];
        
        if(rem<=0){
            ans=ind+1;
            break;
        }
        ind=(ind+1)%7;
        
    }

    cout<<ans<<"\n";
    return 0;
}