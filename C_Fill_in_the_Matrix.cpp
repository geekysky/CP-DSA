#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        if(n==m and n==1){
            cout<<0<<endl;
            cout<<0<<endl;
            continue;
        }
        else if(n==1 and m>1){
            cout<<2<<endl;
            for(int i=1;i<=m;i++){
                cout<<i-1<<" ";
            }
            cout<<endl;
            continue;
        }
        else if(m==1){
            cout<<0<<endl;
            for(int i=1;i<=n;i++){
                cout<<0<<endl;
            }
            continue;
        }
        else if(m==2){
            cout<<2<<endl;
            for(int i=1;i<=n;i++){
                cout<<0<<" "<<1<<endl;
            }
            continue;
        }

        int val=1;
        int arr[n][m];
        for(int i=1;i<=n;i++){
            arr[i-1][0]=val;
            val++;
            if(val==m){
                val=1;
            }
            
        }

        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                if(arr[i][j-1]==m-1){
                    arr[i][j]=0;
                }
                else{
                    arr[i][j]=(arr[i][j-1] + 1);
                }
            }
        }

        cout<<min(n+1,m)<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        // cout<<endl;
    }
    return 0;
}