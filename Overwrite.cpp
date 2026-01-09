#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        
        vector<int> res;
        int idx=-1;
        int val=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(b[i]<val){
                val=b[i];
                idx=i;
            }
        }

        for(int i=idx;i<n;i++){
            res.push_back(b[i]);
        }
        for(int i=0;i<idx;i++){
            res.push_back(b[i]);
        }

        int one=0,two=0;

        for(int idx=0;idx<=(n-m);idx++){
            if(replacement(a,res,idx)){
                
            }
        }
    }
}
