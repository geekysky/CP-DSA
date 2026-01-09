#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n-2);
        for(int i=0;i<n-2;i++){
            cin>>arr[i];
        }

        bool possible=true;
        if(n==3){
            cout<<"YES"<<"\n";
            continue;
        }
        
        for(int i=0;i<n-2;i++){
            if(i+2<n-2 and (arr[i]==1 and arr[i+1]==0 and arr[i+2]==1)){
                possible=false;
                break;
            }
        }

        if(possible){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}