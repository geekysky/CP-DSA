#include<bits/stdc++.h>
using namespace std;
#define ll long long

int query(int i,int j){
    int prod;
    cout<<"? "<<i<<" "<<j<<endl;
    cin>>prod;

    return prod;
}

int main(){
    //direct start with interation 
    vector<int> candidates={4,8,15,16,23,42};
    int first_two=query(1,2);
    int second_third=query(2,3);
    
    vector<int> one,two;
    vector<int> arr(6,0);
    //now find the candidates for first two and second and third snd find out common 
    for(int i=0;i<6;i++){
        if(first_two%candidates[i]==0){
        auto it=find(candidates.begin(),candidates.end(),first_two/candidates[i]);

        if(it!=candidates.end()){
            one.push_back(candidates[i]);
            one.push_back(first_two/candidates[i]);
            break;
        } 
        }
    }

    for(int i=0;i<6;i++){
        if(second_third%candidates[i]==0){
        auto it=find(candidates.begin(),candidates.end(),second_third/candidates[i]);

        if(it!=candidates.end()){
            two.push_back(candidates[i]);
            two.push_back(second_third/candidates[i]);
            break;
        } 
        }
    }

    //now find common 
    if(one[0]==two[0]){
        //this is the second element 
        arr[1]=one[0];
        arr[0]=one[1];

        arr[2]=two[1];
        
    }
    else if(one[0]==two[1]){
        arr[1]=one[0];
        arr[0]=one[1];

        arr[2]=two[0];
    }
    else if(one[1]==two[0]){
        arr[1]=one[1];
        arr[0]=one[0];

        arr[2]=two[1];
    }
    else{
        arr[1]=one[1];
        arr[0]=one[0];

        arr[2]=two[0];
    }

    //three elements have been found out 
    //two queries remaining 
    arr[3]=query(3,4)/arr[2];
    arr[4]=query(4,5)/arr[3];

    //now last element 
    int last_ele;
    for(int i=0;i<6;i++){
        if(find(arr.begin(),arr.end(),candidates[i])==arr.end()){
            arr[5]=candidates[i];
            break;
        }
    }

    cout<<"! ";
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;

}