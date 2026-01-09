#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        vector<int> res;
        if(n==2 or n==3 or n==4){
            cout<<-1<<"\n";
        }
        else{
            for(int i=2;i<=n;i+=2){
                if(i!=4){
                    res.push_back(i);
                }
            }
            res.push_back(4);
            res.push_back(5);
            for(int i=1;i<=n;i+=2){
                if(i!=5){
                    res.push_back(i);
                }
            }
            
            for(int i=0;i<n;i++){
                cout<<res[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}