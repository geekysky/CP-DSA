#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool possible(vector<int> &ropes,int n,int k,double mid){
    int tot_ropes=0;

    for(int i=0;i<n;i++){
        tot_ropes+= (ropes[i]/mid);

        if(tot_ropes>=k)
        return true;
    }

    return false;
}

signed main(){
    int n,k;
    cin>>n>>k;

    vector<int> ropes;

    while(n--){
        int len;
        cin>>len;

        ropes.push_back(len);
    }

    //now let's do binary search on len of ropes 
    double lb=0;
    double ub=1e7;
    double error=1e-6;
    double ans=0;
    int itertations=100;

    for(int i=0;i<itertations;i++){
        double mid=(lb+ub)/2;
        //cout<<lb<<" "<<ub<<" "<<mid<<endl;
        if(possible(ropes,ropes.size(),k,mid)){
            //look for a better ans 
            ans=mid;
            lb=mid+error;
        }
        else{
            ub=mid-error;
        }

    }

    cout<<setprecision(7)<<fixed<<ans<<"\n";


    return 0;
}