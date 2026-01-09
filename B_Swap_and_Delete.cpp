#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int one_cnt=0,zero_cnt=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zero_cnt++;
            }
            else{
                one_cnt++;
            }
        }

        int min_moves=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                //we need a one 
                if(one_cnt>0){
                    one_cnt--;
                }
                else{
                    //we need to delete every character from here till the last 
                    min_moves=i;
                    break;
                }
            }
            else{
                if(zero_cnt>0){
                    zero_cnt--;
                }
                else{
                    min_moves=i;
                    break;
                }
            }
        }
        if(min_moves==-1){
            cout<<0<<"\n";
        }
        else{
        cout<<s.size()-min_moves<<"\n";
        }

    }
    return 0;
}