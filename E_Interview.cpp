#include<bits/stdc++.h>
using namespace std;
#define ll long long

int query(int l, int r) {
    int k = r - l + 1;

    cout << "? " << k << " ";
    for (int i = l; i <= r; i++) {
        cout << i << " ";
    }
    cout << endl;

    int weights;
    cin >> weights;

    return weights;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> stones(n), prefix_stones(n);
        for (int i = 0; i < n; i++) {
            cin >> stones[i];

            if (i == 0) {
                prefix_stones[i] = stones[i];
            } else {
                prefix_stones[i] = prefix_stones[i - 1] + stones[i];
            }
        }

        int s = 1, e = n;  
        while (s <= e) {
            int mid = (s + e) / 2;
            
            if(s==e){
                break;
            }

            int sum_of_weights = query(s, mid);
            int tot_stones;
            
            if (s == 1) {
                tot_stones = prefix_stones[mid - 1];  
            } else {
                tot_stones = prefix_stones[mid - 1] - prefix_stones[s - 2];  
            }

            if (sum_of_weights == tot_stones + 1) {
                // Correct range 
                e = mid ;  
            } else {
                s = mid + 1;
            }
        }

        cout << "! " << e << endl;
    }

    return 0;
}
