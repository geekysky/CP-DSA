#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while (t--)
    {
        /* code */
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int robin_gold=0;
        int people=0;

        for(int i=0;i<n;i++){
            if(arr[i]>=k){
                robin_gold+=arr[i];
            }

            else if(arr[i]==0 and robin_gold>0){
                people++;
                robin_gold--;
            }
        }

        cout<<people<<"\n";

    }
    
    return 0;
}