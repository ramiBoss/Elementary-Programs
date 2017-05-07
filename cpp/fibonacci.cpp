#include<iostream>
#include<stdlib.h>

using namespace std;

void fib(int n){
	int f[10];
	f[0]=0;
	f[1]=1;
	cout<<f[0]<<"\n"<<f[1]<<endl;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+f[i-2];
		cout<<f[i]<<endl;
	}
}

int main(){
	int n;
	cout<<"How many terms?";
	cin>>n;
	cout<<"****and the output is****"<<endl;
	fib(n);
	return 1;
}
