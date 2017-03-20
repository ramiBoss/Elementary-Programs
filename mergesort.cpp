#include<stdlib.h>
#include<iostream>

using namespace std;

int arr[]={7,6,5,4,3,2,1,0,8,9,};

void merge(int start,int mid,int end){
	int temp[end-start+1];
	int i=start,j=mid+1,k=0;
	while(i <= mid && j <= end){
		if(arr[i] < arr[j]){
			temp[k]=arr[i];
			i++;
		}
		else{
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i <= mid)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j <= end){
		temp[k]=arr[j];
		j++;
		k++;
	}
	k=0;
	while(start <= end){
		arr[start]=temp[k];
		start++;
		k++;
	}
}

void mergesort(int start,int end){
	if(start == end)
	return;
	if(start < end){
		int mid=(start+end)/2;
		mergesort(start,mid);
		mergesort(mid+1,end);
		merge(start,mid,end);
	}
}

int main(){
	int len=sizeof(arr)/sizeof(int);
	mergesort(0,len-1);
	for(int i=0;i<len;i++)
	cout<<arr[i]<<" ";
	return 0;
}
