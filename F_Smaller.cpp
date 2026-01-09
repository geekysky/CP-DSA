#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int q;
        cin>>q;

        map<char,int> one;
        map<char,int,greater<char>> two;
        one['a']++;
        two['a']++;
        
        int len1=0,len2=0;
        for(int i=0;i<q;i++){
            int d,k;
            string x;
            cin>>d>>k>>x;
            
            //k no of times x is added to either one or two
            if(d==1){
                //add k times x to one 
                for(int j=0;j<x.size();j++){
                    one[x[j]]+=k;
                }
                len1+=k*x.size();
            }
            else{
                //add k times x to two
                for(int j=0;j<x.size();j++){
                    two[x[j]]+=k;
                }
                len2+=k*x.size();
            }
            
            
            if((one.begin())->first < (two.begin())->first){
                cout<<"YES"<<endl;
            }
            else if(one.size()==1 && two.size()==1 && (one.begin())->first == (two.begin())->first){
                //either one is prefix of two or two is prefix of one
                if(len1>=len2){
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                }
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}