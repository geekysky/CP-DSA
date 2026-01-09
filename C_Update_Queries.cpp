#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        string s;
        cin>>s;

        int ind[m];
        for(int i=0;i<m;i++){
            cin>>ind[i];
        }

        string c;
        cin>>c;

        set<int> unique_ind(ind.begin(), ind.end());
        vector<int> sorted_ind(unique_ind.begin(), unique_ind.end());

        // Sort updates to apply in lexicographical order
        sort(updates.begin(), updates.end());

        // Map to store index and corresponding character updates
        map<int, char> ind_to_char;
        for (size_t i = 0; i < sorted_ind.size(); ++i) {
            ind_to_char[sorted_ind[i]] = updates[i];
        }

        // Apply updates to the string s
        for (const auto &p : ind_to_char) {
            s[p.first - 1] = p.second;
        }

        // Output the updated string
        cout << s << endl;
    }
    return 0;
}