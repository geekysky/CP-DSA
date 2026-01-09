#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;

    while(t--){
        int x;
        cin>>x;

        vector<int> bin_rep(32,0);
        for(int i=0;i<32;i++){
            bin_rep[i]=x%2;
            x/=2;
        }

        //now to find consecutive ones 
        for(int i=0;i<31;i++){
            if(bin_rep[i]==1 and bin_rep[i+1]==1){
                //there r at least two 1s
                bin_rep[i]=-1;
                i++;
                while (bin_rep[i]==1){
                    bin_rep[i]=0;
                    i++;
                }

                //ab agle vale ko one set karna hai 
                bin_rep[i]=1;

                i--;
                //could be a 1righter after we set bin_rep[i]=1
                //then we need to resolve it 
            }
        }

        cout<<32<<"\n";
        for(int i=0;i<32;i++){
            cout<<bin_rep[i]<<" ";
        }
        cout<<"\n";

    }

    return 0;
}