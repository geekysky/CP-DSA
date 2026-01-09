#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool same_parity(int a,int b){

    if(a%2 == b%2)
    return true;

    else
    return false;

} 

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);
        int e=0,o=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==0)
            e++;

            else 
            o++;
        }

        if(o%2==0 and e%2==0)
        cout<<"YES"<<"\n";

        else{
            //like 3 odd numbers and 3 even numbers

            //then array should be one pair in sorted array that arr[i] is even arr[i+1] is odd
            //or vice versa 
            
            bool found=false;
            for(int i=0;i<n;i++){
                if(abs(arr[i]-arr[i+1])==1){
                    found=true;
                    break;
                }
            }

            if(found)
            cout<<"YES"<<"\n";

            else
            cout<<"NO"<<"\n";
            
        
        }

    }

    return 0;
}