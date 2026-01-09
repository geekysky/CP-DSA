#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        //now find len of 1...2...3...
        int longest_inc=0;
        int start=1;

        for(int i=0;i<n;i++){
            if(arr[i]==start){
                longest_inc++;
                start++;
            }
        }

        cout<<(n-longest_inc+k-1)/k<<"\n";
    }
    return 0;
}