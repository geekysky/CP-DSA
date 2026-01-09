#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
 
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n>1 and n%2){
            cout<<-1<<"\n";
        }
        else if(n==1){
            cout<<1<<"\n";
        }
        else{
            //even odd 
            vector<int> arr(n);
            for(int i=0;i<n;i++){
                if((i+1)%2){
                    arr[i]=i+2;
                }
                else{
                    arr[i]=i;
                }
            }
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}