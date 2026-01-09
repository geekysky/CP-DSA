#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr;
        multiset<int> ms;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;

            arr.push_back(x);
            ms.insert(x);
        }

        for(int i=0;i<n;i++){
            if((n-2)%arr[i] == 0){
                //find 
                ms.erase(ms.find(arr[i]));
                if(ms.find((n-2)/arr[i])!=ms.end()){
                    //found 
                    cout<<arr[i]<<" "<<(n-2)/arr[i]<<"\n";
                    break;
                }
                ms.insert(arr[i]);

            }
        }
    }
    return 0;
}