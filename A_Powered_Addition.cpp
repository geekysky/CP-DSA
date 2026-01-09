#include<bits/stdc++.h>
using namespace std;
#define int long long int

int findY(int x, int l) {
    if (l <= x) return 1;

    int required = l - x;
    
    
    int y = 64 - __builtin_clzll(required); 

    return y;
}



signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int largest_till_now=arr[0];
        int t_max=0;
        for(int i=1;i<n;i++){
            if(arr[i]>largest_till_now){
                largest_till_now=arr[i];
            }
            else if(arr[i]<largest_till_now){
                int x=arr[i];
                int l=largest_till_now;
                int y=findY(x,l);
                t_max=max(t_max,y);
                
                largest_till_now=max(largest_till_now, x + (1LL << (y - 1)));
            }
        }
        cout<<t_max<<endl;
    }
    return 0;
}