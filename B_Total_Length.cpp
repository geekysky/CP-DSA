#include<bits/stdc++.h>
using namespace std;
#define int long long int 
 
signed main(){
    int n,s;
    cin>>n>>s;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int left=0,all_len=0;
    int sum=0;

    for(int right=0;right<n;right++){
        sum+=arr[right];

        while(sum>s){
            sum-=arr[left];
            left++;
        }

        //valid left ad valid right ab uske bich m elements kitne hai find karo...
        int ele=right-left+1;
        all_len+=(ele*(ele+1))/2;
    }

    cout<<all_len<<"\n";

    return 0;
}