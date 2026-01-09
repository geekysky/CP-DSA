#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n;
    cin>>n;
    
    int arr[100][100]={0};

    while(n--){
        int llc,llr,urc,urr;
        cin>>llc>>llr>>urc>>urr;

        for(int i=99-(llr-1);i>=99-(urr-1) and i>=0;i--){
            for(int j=llc-1;j<=urc-1;j++){
                arr[i][j]++;
            }
        }
    }
    
    int ans=0;
    for(int x=0;x<100;x++){
        for(int y=0;y<100;y++){
            ans+=arr[x][y];
        }
    }

    cout<<ans<<"\n";
    
    return 0;
}