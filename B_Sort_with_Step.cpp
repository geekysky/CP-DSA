#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int> place_difference(n);
        for(int i=0;i<n;i++){
            place_difference[arr[i]-1]=abs((i+1)-arr[i]);
        }

        int irregular=0;
        for(int i=0;i<n;i++){
            if(place_difference[i]%k!=0){
                irregular++;
            }
        }

        if(irregular==0){
            cout<<0<<"\n";
        }
        else if(irregular==2){
            cout<<1<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
        
    }
    return 0;
}