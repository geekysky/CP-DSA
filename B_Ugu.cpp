#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int one_cnt=0;
        bool one_after_zero=false,zero_after_one=false;
        for(int i=0;i<n;i++){
            if(s[i]=='1')
            one_cnt++;

        }
        int ind=-1;
        for(int i=0;i<n-1;i++){

            if(s[i]=='1'){
                if(ind<0){
                    ind=i;
                }
            }

            if(s[i]=='0' and s[i+1]=='1'){
                one_after_zero=true;
            }

            if(s[i]=='1' and s[i+1]=='0'){
                zero_after_one=true;
            }
        }
        
        if(one_cnt==n or (n-one_cnt)==n or (one_after_zero and !zero_after_one)){
            cout<<0<<"\n";
        }

        else if(zero_after_one and !one_after_zero){
            //11000
            cout<<1<<"\n";
        }
        else{
            //110010
            int diff=0;
            for(int i=n-1;i>=ind;i--){
                if(s[i]!=s[i-1]){
                    diff++;
                }
            }

            cout<<diff-1<<"\n";
        }
    }
    return 0;
}