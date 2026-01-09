#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n;
    cin>>n;

    vector<int> div_freq(1e6+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        div_freq[x]++;
    }

    //now count multiples...and first largest no >=2 multiples 
    for(int i=1e6;i>=1;i--){
        int cnt=0;
        for(int j=i;j<=1e6;j+=i){
            cnt+=div_freq[j];
        }

        if(cnt>1){
            //we have found the largest no with >=2 multiples from the given array
            cout<<i<<"\n";
            break;
        }
    }
    
    return 0;
}