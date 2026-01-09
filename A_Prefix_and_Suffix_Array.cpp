#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(string pre,string suf){
    
    //pre and suf are of same size
    reverse(suf.begin(),suf.end());
    for(int j=0;j<pre.size();j++){
        if(pre[j]!=suf[j]){
            return false;
        }
    }

    return true;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        int size=(2*n)-2;
        vector<string> arr(size);
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
        
        stable_sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
        });

        bool is_pal=true;

        for(int i=size-2;i>=0;i-=2){
            if(!check(arr[i],arr[i+1])){
                is_pal=false;
                break;
            }
        }

        if(is_pal)
        cout<<"YES"<<"\n";

        else
        cout<<"NO"<<"\n";

    }
    return 0;
}