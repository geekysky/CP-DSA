#include<bits/stdc++.h>
using namespace std;
#define int long long int 

signed main() {
    int t;
    cin >> t; 
    vector<int> results; 

    while (t--) {
        int l, r;
        cin >> l >> r; 

        int odd_nums=0;
        for(int i=l;i<=r;i++){
            if(i%2){
                odd_nums++;
            }
        }

        results.push_back(odd_nums/2);

    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
