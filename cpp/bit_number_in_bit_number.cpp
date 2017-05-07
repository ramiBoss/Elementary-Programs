#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
void showbits(long int num){
	int mask,i,k;
	for(i=31;i>=0;i--){
		mask=1<<i;
		k=num&mask;
		k==0?printf("0"):printf("1");
	}
	printf("\n");
}

int placebits(long int num1,long int num2,int i,int j){
	long int max=~0;
	long int left=max-((1<<j)-1);
	long int right=(1<<i)-1;
	cout<<"left number"<<endl;
	showbits(left);
	cout<<"right number"<<endl;
	showbits(right);
	long int n=left|right;
	cout<<"Ored number"<<endl;
	showbits(n);
	return (num1&n)|num2<<i;
}

int main(){
	long int num1,num2;
	cout<<"Enter two number\n";
	cin>>num1;
	cin>>num2;
	cout<<"First number"<<endl;
	showbits(num1);
	cout<<"**********************************"<<endl;
	cout<<"Second number"<<endl;
	showbits(num2);
	cout<<"**********************************"<<endl;
	cout<<"Result"<<endl;
	showbits(placebits(num1,num2,2,6));
	return 0;
}
