#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool possible(int mid,int ele,vector<int> &arr){
    //check if i can pick mid elements 
    if(mid==0){
        return true;
    }

    if(arr[mid-1]<=ele){
        return true;
    }
    else{
        return false;
    }
}

int solve(int ele,vector<int> &arr){
    int low=0,high=arr.size();
    int ans=high+1;
    for(int i=0;i<60;i++){
        int mid=(low+high)/2;

        if(possible(mid,ele,arr)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
} 
int main(){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n),queries(k);

    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    for(int i=0;i<k;i++){
        cin>>queries[i];
    }

    for(int i=0;i<k;i++){
        cout<<solve(queries[i],arr)<<"\n";
    }

    return 0;
}