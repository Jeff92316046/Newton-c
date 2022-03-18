#include<iostream>
#include<math.h>
using namespace std;
double function(int array[],int size,int x){
	int sum = 0,temp = 1;
	for(int i=size-1,I=0;i>=0;i--,I++){
		for(int j=1;j<=i;j++){
			temp = temp*x;
		}
		sum = sum + temp*array[I];
		temp = 1; 
	}
	return sum;
}
int main(){
	int Len = 0,F[100],f[100];
	double X[100];
	cin>>Len;
	for(int i=0;i<=Len-1;i++){
		f[i] = 1;
		X[i] = 1;
		cin>>F[i];
	}
	for(int i=Len-1,I=0;i>=0;i--,I++){
		f[I] = F[I]*i;
	}
	for(int i=0;i<=100;i++){
		if(function(f,Len,X[i]) == 0){
			X[i+1] = X[i];
			break;
		} else {
			X[i+1] = X[i] - (function(F,Len,X[i])/function(f,Len,X[i]));
		}
	}
	for(int i=0;i<=100;i++){
		cout<<X[i]<<endl;
	}

	

} 
