#include <stdio.h>
#include <stdbool.h>
/*
int compare(const void *a, const void *b){
	int val1 = *(int*)a;
	int val2 = *(int*)b;
	printf("a[0] is %d,b[0] is %d\n", val1,val2);
	printf("\n");
	return ( val1 - val2 ); 
}
*/
int compare(const void *a, void *b){

	return(*(int*)a - *(int*)b); 
}
bool twosum(int arr[], int n, int target){
	qsort(arr,n,sizeof(int),compare);
/*	for (int i = 0; i < n; i++) {
  		printf("%d\n", arr[i]);
	}
*/
	int left =0, right = n-1;
	
	while(left<right){
		int sum = arr[left]+arr[right];
		if (sum == target){
			return true;
		}else if (sum < target){
			left++;
		}else{
			right--;
		}
	
	}
	return false;
}


int main(){
	int arr[] = {0, -1, 2, -3, 1};
	int target = 2;
	int n = sizeof(arr) / sizeof (arr[0]);
    	printf("number in array is %d\n",n);
	
	if(twosum(arr,n,target)){
		printf("found target\n");
	}else{
		printf("can't found target\n");
	}
	    
}
