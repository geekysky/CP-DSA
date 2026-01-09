#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while (t--)
    {
        /* code */
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int longest_from_start=1,longest_from_end=1;

        for(int i=1;i<n;i++){
            if(arr[i]!=arr[0]){
                break;
            }
            else{
                longest_from_start++;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(arr[i]!=arr[n-1]){
                break;
            }
            else{
                longest_from_end++;
            }
        }

        
        if(longest_from_end==n)
        cout<<0<<"\n";
        
        else if(arr[0]==arr[n-1])
        cout<<abs((n-longest_from_start)-longest_from_end)<<"\n";

        else
        cout<<min((n-longest_from_start),(n-longest_from_end))<<"\n";



    }
    
    return 0;
}