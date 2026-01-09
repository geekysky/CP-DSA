#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;
    
    int cnt=0;
    while(t--){
        cnt++;
        int n,x;
        cin>>n>>x;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        int ans=1;
        set<int> factors,current;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                factors.insert(i);
                factors.insert(x/i);
            }
        }

        current.insert(1);
        for(int i=0;i<n;i++){
            if(x%arr[i]==0){
                //factor element
                set<int> to_insert;
                for(auto f:factors){
                    if(f%arr[i]==0 and current.find(f/arr[i])!=current.end()){
                        //that factor f can be made 
                        to_insert.insert(f);
                    }
                }

                for(auto x:to_insert){
                    current.insert(x);
                }

                //now check if current set has x or not 
                if(current.find(x)!=current.end()){
                    ans++;
                    current.clear();
                    current.insert(1);
                    current.insert(arr[i]);
                }
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}