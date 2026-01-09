#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool possible(int mid, vector<int>& numbers, vector<int>& prices, string s, int r) {
    int each_b = 0, each_s = 0, each_c = 0;

    for (char ch : s) {
        if (ch == 'B') each_b++;
        else if (ch == 'S') each_s++;
        else if (ch == 'C') each_c++;
    }

    int required_buns = mid * each_b;
    int required_sausage = mid * each_s;
    int required_cheese = mid * each_c;

    int extra_buns = max(0LL, required_buns - numbers[0]);
    int extra_sausage = max(0LL, required_sausage - numbers[1]);
    int extra_cheese = max(0LL, required_cheese - numbers[2]);
    
    vector<int> extra;
    extra.push_back(extra_buns);
    extra.push_back(extra_sausage);
    extra.push_back(extra_cheese);
    
    for(int i=0;i<3;i++){
        if(extra[i]*prices[i] > r){
            return false;
        }
        
        r-=extra[i]*prices[i];
    }
    
    return true;
}

signed main(){
    string s;
    cin>>s;
    
    vector<int> numbers,prices;
    for(int i=0;i<3;i++){
        int x;
        cin>>x;
        
        numbers.push_back(x);
    }
    
    for(int i=0;i<3;i++){
        int x;
        cin>>x;
        
        prices.push_back(x);
    }
    
    int r;
    cin>>r;
    
    int low=0,high=1e12+100;
    int ans=high+1;
    
    while(low<=high){
        int mid=(low+high)/2;
        
        if(possible(mid,numbers,prices,s,r)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
    
}