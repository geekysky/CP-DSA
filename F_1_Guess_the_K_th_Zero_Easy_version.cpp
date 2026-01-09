#include<bits/stdc++.h>
using namespace std;
#define ll long long

int query(int l,int r){
    int sum;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>sum;

    return sum;
}

int main(){
    int n,t;
    cin>>n>>t;

    int k;
    cin>>k;

    int s=1,e=n,rem_k=k;

    while(s<=e){
        
        int mid=(s+e)/2;
        if(s==e){
            cout<<"! "<<mid<<endl;
            break;
        }

        int first_half=query(s,mid);
        //can't make both queries 
        int zeroes_in_first_half=(mid-s)+1 - first_half;

        if(rem_k<=zeroes_in_first_half){
            //kth zero lies in this half 
            e=mid;
        }
        else{
            s=mid+1;
            rem_k=rem_k-zeroes_in_first_half;
        }

    }

    return 0;
}