#include <bits/stdc++.h>
using namespace std;
#define int long long int

int log_of_3(int a){
    int cnt=0;
    while(a){
        a/=3;
        cnt++;
    }
    
    return cnt;
}

signed main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int pref[200001];
	pref[0]=0;
	pref[1]=1;
	for(int i=2;i<200001;i++){
        pref[i]=pref[i-1]+log_of_3(i);
	}

	int t;
	cin>>t;
	
	while(t--){
	    int l,r;
	    cin>>l>>r;
	    
	    int first_log=log_of_3(l);
	    
		//my earlierapproach was O(log_3(r)*(r-l)*t) >>> 1e8
		//so tle

		int ans=2*first_log + pref[r]-pref[l];
		cout<<ans<<endl; 

		
	    
	}
	
	return 0;

}
