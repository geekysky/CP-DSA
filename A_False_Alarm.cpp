#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        bool used=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                //x should be used
                for(int j=n-1;j>=i;j--){
                    if(arr[j]==1){
                        //last locked door
                        int dist=j-i+1;

                        if(dist>x){
                            cout<<"NO"<<endl;
                        }
                        else{
                            cout<<"YES"<<endl;
                        }

                        used=1;
                        break;
                    }
                }
            }

            if(used){
                break;
            }
        }

    }
    return 0;
}