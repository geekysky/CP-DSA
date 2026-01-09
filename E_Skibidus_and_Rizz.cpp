#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        if(abs(n-m)>k){
            cout<<-1<<endl;
            continue;
        }
        else if(max(n,m)<k){
            cout<<-1<<endl;
            continue;
        }
        else{
            string ans="";

            if(n>=m){
                for(int i=0;i<k;i++){
                    ans+="0";
                }
                n-=k;
                while(n>0 and m>0){
                    if(ans.back()=='0'){
                        ans+="1";
                        m--;
                    }
                    else{
                        ans+="0";
                        n--;
                    }
                }

                while(n>0){
                    ans+="0";
                    n--;
                }
                while(m>0){
                    ans+="1";
                    m--;
                }
            }
            else if(m>n){
                for(int i=0;i<k;i++){
                    ans+="1";
                }
                m-=k;
                while(n>0 and m>0){
                    if(ans.back()=='1'){
                        ans+="0";
                        n--;
                    }
                    else{
                        ans+="1";
                        m--;
                    }
                }

                while(n>0){
                    ans+="0";
                    n--;
                }
                while(m>0){
                    ans+="1";
                    m--;
                }
            }

            cout<<ans<<endl;
            
        }
    }
    return 0;
}