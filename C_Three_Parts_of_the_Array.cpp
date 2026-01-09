#include<bits/stdc++.h>
using namespace std;
#define int long long int 

signed main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int best_sum = 0;
    int left = 0, right = n - 1;

    int s1 = arr[0], s3 = arr[n-1];  

    while(left<right){
        if(s1 > s3){
            right--;
            s3+=arr[right];  
        }
        else if(s1 < s3){
            left++; 
            s1+=arr[left]; 
        }
        else{
            // A better common sum found for s1 and s3
            best_sum = s1;
            left++; 
            s1+=arr[left];
        }
    }

    cout << best_sum << "\n";

    return 0;
}
