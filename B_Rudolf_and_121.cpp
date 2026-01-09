#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while (t--)
    {
        /* code */
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<n-2;i++){
            int min_ops=min({arr[i],arr[i+1]/2,arr[i+2]});

            arr[i]-=min_ops;
            arr[i+1]-=(min_ops*2);
            arr[i+2]-=min_ops;
        }
        
        bool flag=true;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                flag=false;
            }
        }

        if(flag)
        cout<<"YES"<<"\n";

        else
        cout<<"NO"<<"\n";


    }
    
    return 0;
}