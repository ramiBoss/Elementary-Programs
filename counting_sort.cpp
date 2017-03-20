#include <iostream>

using namespace std;

int main(){
	int a[]={1,5,3,6,7,6,2,9,1};
	int a_size=sizeof(a)/sizeof(int);
	int c[10],b[a_size];
	
	for(int i=0;i<10;i++)
	c[i]=0;
	
	for(int i=0;i<10;i++)
	cout<<c[i]<<" ";
	
	cout<<endl;
	for(int i=1;i<=a_size;i++)
	c[a[i]]=c[a[i]]+1;
	
	for(int i=0;i<10;i++)
	cout<<c[i]<<" ";
	
	for(int i=1;i<=a_size;i++)
	c[i]=c[i]+c[i-1];
	
	for(int i=a_size;i>=1;i--){
		b[c[a[i]]]=a[i];
		c[i]=c[i]-1;
	}
	for(int i=0;i<a_size;i++)
	cout<<b[i]<<" ";
	return 0;
}
