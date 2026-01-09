#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;
        
        int ans=0;
        for(int i=0;i<n;i++){
            int freq[10]={0};
            int distinct=0,max_freq=0;
            for(int j=i;j<min(i+100,n);j++){
                if(freq[s[j]-'0']==0){
                    //new character 
                    distinct++;
                }
                freq[s[j]-'0']++;

                for(int i=0;i<10;i++){
                    max_freq=max(max_freq,freq[i]);
                }

                if(max_freq<=distinct){
                    //exceed nahi hua hai for the max occuring character 
                    ans++;
                }
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}