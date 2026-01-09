#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n;
    cin>>n;

    vector<int> is_prime(n+1,1);
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=0;
            }
        }
    }

    vector<int> res;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            int num=i;
            while(num<=n){
                res.push_back(num);
                num*=i;
            }
        }
    }

    cout<<res.size()<<"\n";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<"\n";

    return 0;
}