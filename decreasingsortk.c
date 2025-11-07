#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void* b){
	return(*(int *)b -*(int *)a);
}

void kLargest(int *arr,int*k_arr,int n, int k){
	

	qsort(arr,n,sizeof(arr[0]),compare);
	
	for(int i=0;i<k;i++){
		k_arr[i]=arr[i];
	}

}


void main(){
	int arr[] ={1, 23, 12, 9, 30, 2, 50};
	int k=3;
	int n = sizeof(arr)/sizeof(arr[0]);
	char a = -1;
	int k_arr[k];
	
	kLargest(arr,k_arr,n,k);
	for(int i=0;i<k;i++){
		printf("%d\n",k_arr[i]);
	}
	printf("%d\n",k_arr[-1]);
	
}
