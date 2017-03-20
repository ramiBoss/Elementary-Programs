#include<stdlib.h>
/* The trick is to perform counting sort of each and every digit and to reach out to every digit
use (arr[i]/exp)%10 after all the digits are sorted the numbers comes out to be sorted too*/




#include<iostream>
#include <algorithm>

#define DEC 10
using namespace std;

int arr[]={7,16,45,54,3,2,8,9};

void counting(int size,int place){
	int b[size];
	int c[DEC]={0};
		//cout<<"1 here";
	for(int i=0 ; i<size ; i++)
		c[ (arr[i]/place)%10 ]++;
		//cout<<"2 here";
	for(int i=1 ; i<DEC ; i++)
		c[i]=c[i]+c[i-1];
	//cout<<"3 here";
	for(int i=size-1 ; i>=0 ; i--){
		b[ c[ (arr[i]/place)%10 ] -1] = arr[i];
		c[ (arr[i]/place)%10 ]--;	
	}
	//	cout<<"4 here";
	for(int i=0 ; i<size ; i++)
		arr[i]=b[i];		
}


int main(){
	int size=sizeof(arr)/sizeof(arr[0]);
	int max=*std::max_element(arr,arr+size);
	cout<<max<<" "<<size;
	for(int i=1;(max/i) > 0;i*=10)
	counting(size,i);
	
	for(int i=0;i < size;i++)
	cout<<arr[i]<<" ";
	return 0;
}
