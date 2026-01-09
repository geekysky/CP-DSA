#include<bits/stdc++.h>
using namespace std;
#define lld long double

bool checker(long long mid,vector<lld> arr,lld sum,lld average){
    lld n=arr.size();
    arr[n-1]+=mid;

    sum+=mid;
    average=sum/n;

    auto it=lower_bound(arr.begin(),arr.end(),average/2);
    lld unhappy=it-arr.begin();

    return unhappy>n/2 ;
}

int main(){
    lld t;
    cin>>t;

    while(t--){
        lld n;
        cin>>n;
        
        vector<lld> arr(n);
        for(lld i=0;i<n;i++){
            cin>>arr[i];
        }

        if(n==1 or n==2){
            cout<<-1<<"\n";
        }

        else{
            sort(arr.begin(),arr.end());
            
            lld sum=0;
            for(lld i=0;i<n;i++){
                sum+=arr[i];
            }

            lld average=sum/n;

            auto it=lower_bound(arr.begin(),arr.end(),sum/(2*n));
            lld unhappy=it-arr.begin();
            
            if(unhappy>n/2){
                cout<<0<<"\n";
            }
            else{
                long long s=0,e=1e18;
                long long ans=e+1;
                for(lld i=0;i<100;i++){
                    long long mid=(s+e)/2;
                    

                    if(checker(mid,arr,sum,average)){
                        ans=mid;
                        e=mid-1;
                    }
                    else{
                        s=mid+1;
                    }
                }

                cout<<ans<<"\n";
            }

        }
    }
    return 0;
}