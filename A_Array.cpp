#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	//freopen("in","r",stdin);
	int n;
	int A[150];
	scanf("%d",&n);
	int posit = 0,negat = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		if(A[i] > 0)
			posit++;
		if(A[i] < 0)
			negat++;
	}
	vector <int> zero,pos,neg;
	if(posit > 0){
		bool flag1=true,flag2=true;
		for(int i=0;i<n;i++){
			if(A[i] < 0 && flag1){
				neg.push_back(A[i]);
				flag1=false;
			}
			else if(A[i] > 0 && flag2){
				pos.push_back(A[i]);
				flag2=false;
			}
			else{
				zero.push_back(A[i]);
			}
		}
	}
	else{
		bool flag1=true;
		int count =0;
		for(int i=0;i<n;i++){
			if(A[i] < 0 && flag1){
				neg.push_back(A[i]);
				flag1=false;
			}
			else if(A[i] < 0 && count < 2){
				pos.push_back(A[i]);
				count++;
			}
			else{
				zero.push_back(A[i]);
			}
		}

	}
	printf("%d",neg.size());
	for(int i=0;i<neg.size();i++)
		printf(" %d",neg[i]);
	printf("\n");
	printf("%d",pos.size());
	for(int i=0;i<pos.size();i++)
		printf(" %d",pos[i]);
	printf("\n");
	printf("%d",zero.size());
	for(int i=0;i<zero.size();i++)
		printf(" %d",zero[i]);
	printf("\n");

}