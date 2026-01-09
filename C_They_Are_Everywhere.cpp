#include<bits/stdc++.h>
using namespace std;

int minLengthSubarrayWithKDistinct(string &arr) {
    int n = arr.size();
    int left = 0;
    map<char, int> count_map; 
    int distinct_count = 0;
    int min_len = INT_MAX; 
    map<char,int> dist;
    for(int i=0;i<n;i++){
        dist[arr[i]]++;
    }
    
    int K=dist.size();

    for (int right = 0; right < n; ++right) {
        count_map[arr[right]]++;
        
        if (count_map[arr[right]] == 1) {
            distinct_count++;
        }
        
        while (distinct_count == K) {
            min_len = min(min_len, right - left + 1);

            count_map[arr[left]]--;
            if (count_map[arr[left]] == 0) {
                distinct_count--;  
            }
            left++;
        }
    }

    
    return (min_len == INT_MAX) ? 0 : min_len;
}

int main() {
    int n;
    cin>>n;
    
    string s;
    cin>>s;
     
    cout<<minLengthSubarrayWithKDistinct(s)<<"\n";

    return 0;
}
