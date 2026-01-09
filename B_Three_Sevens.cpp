#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;

    while(t--){
        int m;
        cin >> m;
        
        int p_count[50001] = {0};
        vector<vector<int>> store;
        
        for(int j = 0; j < m; j++){
            int n;
            cin >> n;
            
            vector<int> arr;
            for(int i = 0; i < n; i++){
                int x;
                cin >> x;
                
                p_count[x] = j + 1;
                arr.push_back(x);
            }

            store.push_back(arr);
        }

        // for(int i = 0; i < 11; i++){
        //     cout << p_count[i] << " ";
        // }
        // cout << endl;

        bool foundValid = false;
        int flag=0;
        vector<int> ans;
        for(int i = 0; i < m; i++){
            vector<int> temp = store[i];
            int prev_size=ans.size();
            for(int j = 0; j < temp.size(); j++){
                if(p_count[temp[j]] == (i + 1)){
                    //last participation day should be i+1
                    ans.push_back(temp[j]);
                    break;
                }
            }
            int curr_size=ans.size();

            if(prev_size==curr_size){
                //no winner possible for that day 
                flag=-1;
                break;
            }
 
            
        }

        if(flag==-1){
            cout<<-1<<'\n';
        }
        else{
            for(auto x:ans){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
