#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[2*n];
        int odd_num=0,even_num=0;
        for(ll i=0;i<n*2;i++){
            cin>>arr[i];

            if(arr[i]%2==0)
            even_num++;

            else
            odd_num++;
        }

        if(even_num==odd_num)
        cout<<"Yes"<<"\n";

        else
        cout<<"No"<<"\n";


    }
    return 0;
}