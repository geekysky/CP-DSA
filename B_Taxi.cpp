#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    int arr[n];
    vector<int> mark(5);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mark[arr[i]]++;
    }

    int tot_vehicles = 0;

    // Groups of size 4 each require one vehicle
    tot_vehicles += mark[4];
    mark[4] = 0;

    // Groups of size 3 can be paired with groups of size 1
    int pos_13_pairings = min(mark[1], mark[3]);
    tot_vehicles += pos_13_pairings;
    mark[1] -= pos_13_pairings;
    mark[3] -= pos_13_pairings;

    // Groups of size 2 can be paired together
    int pos_22_pairings = mark[2] / 2;
    tot_vehicles += pos_22_pairings;
    mark[2] -= pos_22_pairings * 2; // Update correctly after pairing

    // Remaining groups of size 3 each need one vehicle
    tot_vehicles += mark[3];
    mark[3] = 0;

    // Pairs of two groups of size 1 with one group of size 2 can share one vehicle
    // mark[2] is 1 here..not two or three or else we would've paired it up earlier 
    //cout<<mark[1]<<" "<<mark[2]<<" "<<mark[3]<<" "<<mark[4]<<endl;
    int pair_112 = min(mark[1] / 2, mark[2]);
    tot_vehicles += pair_112;
    mark[1] -= pair_112 * 2;
    mark[2] -= pair_112;

    //now either only 1s are remaining or 12 
    
    //cout<<mark[1]<<" "<<mark[2]<<endl;

    if(mark[2]){
        //one 2 is remaining 
        tot_vehicles+=1;
        mark[1]=0;
        mark[2]=0;
    }

    else{
        // 1 1 1 1...
        tot_vehicles+=(mark[1]+3)/4;
        mark[1]=0;
    }



    cout << tot_vehicles << endl;

    return 0;
}
