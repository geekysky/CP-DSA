#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        bool correct=true;
        for(int i=0;i<n;i++){
            if(arr[i]!=(i+1)){
                if(i==0){
                    if(arr[1]-arr[0]==1){
                        swap(arr[0],arr[1]);
                    }
                }
                if(i==n-1){
                    if(abs(arr[n-2]-arr[n-1])==1){
                        swap(arr[n-2],arr[n-1]);
                    }
                }

                else{
                    if(arr[i]>(i+1)){
                        if(abs(arr[i+1]-arr[i]==1)){
                            swap(arr[i+1],arr[i]);
                        }
                    }
                    else {
                        //arr[i]<(i+1)
                        if(abs(arr[i-1]-arr[i])==1){
                            swap(arr[i-1],arr[i]);
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            if(arr[i]!=(i+1)){
                correct=false;
                break;
            }
        }

        if(correct){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
        
    }
    return 0;
}