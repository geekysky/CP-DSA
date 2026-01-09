#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
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

        int check[n+1]={0};

        check[arr[0]]=1;

        //first wala aake baith gaya hai 
        bool flag=true;
        for(int i=1;i<n;i++){
            if(!check[arr[i]]){
                //unoccupied 
                if(arr[i]==1){
                    //check for second seat 
                    if(check[2]==0){
                        flag=false;
                        break;
                    }
                    else{
                        //occupied
                        check[1]=1;
                    }
                }
                else if(arr[i]==n){
                    //last seat m baithna chahta hai 
                    if(check[n-1]==0){
                        flag=false;
                        break;
                    }
                    else{
                        //safe to occupy 
                        check[n]=1;
                    }
                }
                else{
                    //bich ki koi seat 
                    if(check[arr[i]-1]==0 and check[arr[i]+1]==0){
                        //both front n back r unoccupied 
                        flag=false;
                        break;
                    }
                    else{
                        //either one is occupied 
                        check[arr[i]]=1;
                    }
                }
            }
        }

        if(flag)
        cout<<"YES"<<"\n";

        else
        cout<<"NO"<<"\n";


    }
    
    return 0;
}