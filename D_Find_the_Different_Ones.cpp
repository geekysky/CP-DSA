#include<bits/stdc++.h>
using namespace std;
#define int long long int 

bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int q;
        cin>>q;
        
        vector<pair<int,int>> vec;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[i-1]){
                vec.push_back({arr[i-1],cnt});
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        
        //for last distinct element 
        vec.push_back({arr[n-1],cnt});

        while(q--){
            int l,r;
            cin>>l>>r;
            
            //to find which segment my l lies in 
            auto it=upper_bound(vec.begin(),vec.end(),make_pair(0,l),cmp);

            if(it==vec.end()){
                cout<<-1<<" "<<-1<<"\n";
            }
            else{
                it--;
                if(it-vec.begin()==(vec.size()-1)){
                    cout<<-1<<" "<<-1<<"\n";
                }

                else if(vec[it-vec.begin()+1].second>r)
                cout<<-1<<" "<<-1<<"\n";

                else
                cout<<l<<" "<<vec[it-vec.begin()+1].second<<"\n";
            }
        }
        cout << "\n";
    }
}
