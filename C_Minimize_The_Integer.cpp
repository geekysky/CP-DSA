#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin >> t;

    while(t--){
        string num; // Input as a string
        cin >> num;

        vector<char> odd, even;

        for(int i = 0; i < num.size(); i++){
            if((num[i] - '0') % 2 == 0){
                even.push_back(num[i]);
            }
            else{
                odd.push_back(num[i]);
            }
        }

        string ans = "";
        if(odd.empty() || even.empty()){
            cout << num << "\n";
        }
        else{
            int s = 0, e = 0;

            while(s < even.size() && e < odd.size()){
                if((odd[e] - '0') < (even[s] - '0')){  // Corrected comparison
                    ans += odd[e];
                    e++;
                }
                else {
                    ans += even[s];
                    s++;
                }
            }

            while(s < even.size()){
                ans += even[s];
                s++;
            }
            while(e < odd.size()){
                ans += odd[e];
                e++;
            }

            cout << ans << "\n";
        }
    }
    return 0;
}
