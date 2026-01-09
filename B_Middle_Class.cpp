#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        sort(arr,arr+n);
        if(n==1){
            (*arr)>=x ? cout<<1<<"\n":cout<<"0"<<"\n";
        }
        else{
            //construct suffix array 
            int suffix[n];
            for(int i=n-1;i>=0;i--){
                if(i==(n-1)){
                    suffix[i]=arr[i];
                }
                else{
                    suffix[i]=suffix[i+1]+arr[i];
                }
            }

            int max_wealthy=0;
            for(int i=n-1;i>=0;i--){
                if(suffix[i] >= (n-i)*x){
                    max_wealthy=(n-i);
                }
                else{
                    break;
                }
            }

            cout<<max_wealthy<<"\n";
        }
    }
    return 0;
}