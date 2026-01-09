#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int n,k1,k2;
    cin>>n>>k1>>k2;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;

        arr[i]=abs(arr[i]-ele);

        pq.push(arr[i]);
    }

    int ans=0,k=k1+k2;

    while(k>0){
        int val = pq.top();
        pq.pop();
        
        k--;
        pq.push(abs(val-1));
    }

    while(!pq.empty()){
        ans +=(pq.top() * pq.top());

        pq.pop();
    }

    cout<<ans<<endl;

    return 0;
}