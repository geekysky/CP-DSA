#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        char arr[n][n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }

        //no of reduced cells = n2/k2
        for(int i=0;i<n;i+=k){
            for(int j=0;j<n;j+=k){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }

        //cout<<"\n";

    }

    return 0;
}