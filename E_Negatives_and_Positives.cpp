#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool cmp(int a,int b){
    return abs(a)<abs(b);
}

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        int zero=0,neg=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];

            if(arr[i]==0){
                zero++;
            }

            if(arr[i]<0){
                neg++;
            }
        }
        
        int sum=0;
        if(neg==0){
            // all ele>= 0
            
            for(int i=0;i<n;i++){
                sum+=arr[i];
            }
            cout<<sum<<"\n";
        }

        else if(neg%2==0 or (neg%2 and zero)){
            for(int i=0;i<n;i++){
                sum+=abs(arr[i]);
            }

            cout<<sum<<"\n";
        }

        else{
            sort(arr,arr+n,cmp);

            for(int i=1;i<n;i++){
                sum+=abs(arr[i]);
            }

            cout<<sum-abs(arr[0])<<"\n";
        }
    }
    return 0;
}