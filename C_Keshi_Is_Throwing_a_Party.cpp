#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool checker(int mid,vector<int> &a,vector<int> &b){
    int taken=0;

    for(int i=0;i<a.size();i++){
        if(taken<=b[i] and (mid-(taken+1))<=a[i]){
            taken++;
        }
        if(taken==mid){
            break;
        }
    }

    return taken==mid;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }

        //binary search for max number of people that can be invited 
        int l=1,u=n;
        int ans=u+1;
        
        //checking if we can invite exactly mid people 
        for(int i=0;i<100;i++){
            int mid=(l+u)/2;

            if(checker(mid,a,b)){
                // check towards right 
                l=mid+1;
                ans=mid;
            }
            else{
                u=mid-1;
            }
        }

        cout<<ans<<"\n";


    }
    return 0;
}