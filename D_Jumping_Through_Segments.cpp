#include<bits/stdc++.h>
using namespace std;
#define int long long int

pair<int,int> intersection(pair<int,int> one, pair<int,int> two){
    return {max(one.first, two.first), min(one.second, two.second)};
}

//PF looks like FFFFFTTTT...
bool possible(vector<pair<int,int>> &ranges, int mid){
    pair<int,int> beg={0,0};

    for(auto x : ranges){
        beg = {beg.first - mid, beg.second + mid};

        pair<int,int> seg_range = x;
        pair<int,int> inter = intersection(seg_range, beg);

        if(inter.first <= inter.second){
            beg = inter;
        }
        else{
            return false;
        }
    }

    return true;
}

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        vector<pair<int,int>> segments;
        for(int i = 0; i < n; i++){
            int l, r;
            cin>>l>>r;
            segments.push_back({l,r});
        }

        int lb = 0, ub = 1e9;
        int ans=0;

        while(lb <= ub){
            int mid = (lb + ub) / 2;

            if(possible(segments, mid)){
                ans = mid;
                ub = mid - 1;
            }
            else{
                lb = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
