#include<bits/stdc++.h>
using namespace std;
#define int long long int 

//0 is allowed as an elements as it's non negative 
bool possible_median(int mid,int n,int s){
    int elements=n/2 + 1;

    if(elements*mid <=s){
        return true;
    }
    else{
        return false;
    }
}

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,s;
        cin>>n>>s;

        int low=0;
        int high=s;
        int ans=high+1;

        while(low<=high){
            int mid=(low+high)/2;

            if(possible_median(mid,n,s)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        cout<<ans<<"\n";

    }

    return 0;
} 