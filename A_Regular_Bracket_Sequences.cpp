#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    //can be done in recursive time 

    int t;
    cin>>t;

    while(t--){
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            string sequence;
            for (int k = 0; k < j; ++k) {
                sequence += "()";
            }
            for (int k = 0; k < n - j; ++k) {
                sequence += "(";
            }
            for (int k = 0; k < n - j; ++k) {
                sequence += ")";
            }
            cout << sequence << endl;
        }
    }
    return 0;
}