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

        int corr_places=0;
        vector<int>subs;

        for(int i=0;i<n;i++){
            if(arr[i]==i+1){
                corr_places++;
            }
        }

        // if(corr_places==n){
        //     cout<<0<<"\n";
        // }
        
        int temp=-1;
        //correct sub_arr - 1 
        //wrong sub_arr - 0
        
        if(n==2){
            if(arr[0]==1 and arr[1]==2)
            cout<<0<<"\n";

            else
            cout<<1<<"\n";
        }

        else{
        for(int i=0;i<n;i++){
            int curr;
            if(arr[i]!=(i+1)){
                //wrong place 
                curr=0;

                if(curr!=temp){
                    //update 
                    temp=curr;
                    subs.push_back(temp);
                }
            }
            else{
                //correct place 
                curr=1;

                if(curr!=temp){
                    //update 
                    temp=curr;
                    subs.push_back(temp);
                }
            }
        }
        
        int ans=-1;
        //subs array correct 
        for(int i=1;i<subs.size()-1;i++){
            if(subs[i]==1 and subs[i-1]==0 and subs[i+1]==0){
                ans=2;
            }
        }
        
        // cout<<ans<<'\n';

        if(corr_places==n)
        cout<<0<<"\n";
        
        else if(ans==-1)
        cout<<1<<"\n";

        else
        cout<<2<<"\n";

        //cout<<endl;
        }
        
    }
    return 0;
}