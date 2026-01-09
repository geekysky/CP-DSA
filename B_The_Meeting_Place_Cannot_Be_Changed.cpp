#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool check(double mid, vector<pair<int,int>> arr){
    //find intersection region
    double l=-1e9;
    double r = 1e9;

    for(int i=0;i<arr.size();i++){
        l = max(l,(double)arr[i].first - (double)(arr[i].second * mid));
        r = min(r,(double)arr[i].first + (double)(arr[i].second * mid));
    }

    return l <= r;
}

signed main(){
    int n;
    cin>>n;

    vector<pair<int,int>> friends(n);

    for(int i=0;i<n;i++){
        cin>>friends[i].first;
    }
    
    for(int i=0;i<n;i++){
        cin>>friends[i].second;
    }

    double ans = 0.0;
    double low = 0.0;
    double high = 1e10;

    for(int i=1;i<=100;i++){
        double mid = (low+high)/2.0;

        if(check(mid,friends)){
            ans = mid;
            high = mid;
        }
        else{
            low = mid;
        }
    }

    cout<<fixed<<setprecision(12)<<ans<<endl;

    return 0;
}

bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }

    return a.first > b.first;
}

int main(){
    int n;
    cin>>n;

    map<int,int> arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;

        arr[ele]++;
    }
    
    vector<pair<int,int>> ans;
    for(auto it:arr){
        ans.push_back({it.first,it.second});
    }

    sort(ans.begin(),ans.end(),cmp);

    for(auto ele:arr){
        cout<<ele.first<<" ";
    }
    


}