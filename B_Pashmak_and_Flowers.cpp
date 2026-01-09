#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int smallest=0, largest=0;

    sort(arr.begin(), arr.end());
    int idx=0;
    while(idx < n && arr[idx]==arr[0]){
        smallest++;
        idx++;
    }

    idx=n-1;
    while(idx >= 0 && arr[idx]==arr[n-1]){
        largest++;
        idx--;
    }

    // If all elements are same, result is n*(n-1)/2
    if(arr[0] == arr[n-1]){
        cout<<0<<" "<<(n*(n-1)/2)<<"\n";
    } else {
        cout<<arr[n-1]-arr[0]<<" "<<(smallest*largest)<<"\n";
    }

    return 0;
}