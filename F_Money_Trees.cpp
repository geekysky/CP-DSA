#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n), h(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < n; i++){
            cin >> h[i];
        }

        // split the array
        vector<pair<int, int>> subarrs;
        int beg = 0, end = 0;
        for(int i = 0; i < n - 1; i++){
            if(h[i] % h[i + 1] == 0 && h[i + 1] != 0){
                end++;
            } else {
                subarrs.push_back({beg, end});
                beg = i + 1;
                end = i + 1;
            }
        }
        subarrs.push_back({beg, end});

        int ans = 0;

        for(auto ele : subarrs){
            int temp_len = 0;
            int start = ele.first;
            int end = ele.second;

            // for every valid subarray find the longest len where sum <= k 
            int left = start, right = start;

            // apply increasing technique
            int sum = 0;
            while(right <= end){  
                sum += a[right];

                while(sum > k){
                    sum -= a[left];
                    left++;
                }

                temp_len = max(temp_len, right - left + 1);
                right++;
            }

            ans = max(ans, temp_len);
        }

        cout << ans << "\n";
    }

    return 0;
}
