#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        char arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }

        int most_symbols=INT_MIN;
        int find_row=-1;
        for(int i=0;i<n;i++){
            int thatrow=0;
            for(int j=0;j<m;j++){
                if(arr[i][j]=='#'){
                    thatrow++;
                }
            }

            //agar us row m pehle vale se zyada ho then update
            if(thatrow>=most_symbols){
                find_row=i+1;
                most_symbols=thatrow;
            }
        }

        //ab us row ka centre point nikalo 
        int mid_len=0;
        bool care=true;
        int temp=0;
        for(int i=0;i<m;i++){
            if(arr[find_row-1][i]=='#'){
                //chalu ho gaya continuous #s
                if(care){

                    temp=i-0;
                    care=false;
                } 
                mid_len++;
            }
        }
        int find_col = (mid_len+1)/2 + temp;
        cout<<find_row<<" "<<find_col<<"\n";

    }
    return 0;
}