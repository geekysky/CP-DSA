#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool checker(int mid,vector<int> arr,int n){
    bool opn=false;
    int i=0;
    while(i<n){

        if(i==n-1){
            //last element reached and was not marked earlier 
            if(opn){
                //special operation was used up 
                return false;
            }
        }
        else if(arr[i+1]-arr[i] > mid){
            if(!opn){
            opn=true;
            i++;
            }
            else{
                return false;
            }
        }
        else{
            //nearest next cell from arr[i] can be marked black along with it 
            i+=2;
        }
    }    

    return true;
}

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int low=1,high=1e18;
        int ans=high+1;

        while(low<=high){
            int mid=(low+high)/2;

            if(checker(mid,arr,n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}