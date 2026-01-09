#include<bits/stdc++.h>
using namespace std;
#define int long long int

string decimal_binary(int num){
    string binary = "";
    while(num>0){
        binary += to_string(num%2);
        num /= 2;
    }
    reverse(binary.begin(),binary.end());
    return binary;
}
signed main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<string> arr(m+1);
    for(int i=0;i<=m;i++){
        int x;
        cin>>x;

        //add padding if it's length is less than 20
        string temp=decimal_binary(x);
        if(temp.size()<20){
            string padding="";
            for(int i=0;i<20-temp.size();i++){
                padding+="0";
            }
            temp=padding+temp;
        }

        arr[i]=temp;
    }

    int ans=0;
    for(int i=0;i<m;i++){
        int cnt=0;
        for(int j=0;j<20;j++){
            if(arr[i][j]!=arr[m][j]){
                cnt++;
            }
        }
        if(cnt<=k){
            ans++;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}