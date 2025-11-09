#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char errMsg[32]={"Can't find\n"};

struct node{
	char* key;
	char* value;
	struct node* next;
};

struct hashMap{
	//int numOfItems;
	int capacity;
	struct node **arr;
};

bool initHashMap(struct hashMap* map){
	if(map == NULL)
		return false;
	//map->numOfItems=0;
	map->capacity=100;
	
	map->arr = (struct node**)malloc(sizeof(struct node*)*(map->capacity));
	return true;

}
int setNode(struct node* node, char* key, char* value){
	node->key = key;
	node->value = value;
	node->next= NULL;
}
int hashfunction(struct hashMap* map, char* key){

    int bucketIndex;
    int sum = 0, factor = 31;
   // printf("---------------------start------------------------\n");
    for (int i = 0; i < strlen(key); i++) {

        // sum = sum + (ascii value of
        // char * (primeNumber ^ x))...
        // where x = 1, 2, 3....n
        sum = ((sum % map->capacity) + (((int)key[i]) * factor) % map->capacity) % map->capacity;

        // factor = factor * prime
        // number....(prime
        // number) ^ x
        factor = ((factor % __INT16_MAX__)* (31 % __INT16_MAX__))% __INT16_MAX__;
      //  printf("sum is %d,factor is %d, int16_MAXis %d\n",sum,factor,__INT16_MAX__);
    }
	//printf("---------------------end------------------------\n");
    bucketIndex = sum;
    //printf("sum is %d\n",sum);
    return bucketIndex;


	//return 5;
}
void insert(struct hashMap* map, char* key, char* value){
	
	int index = hashfunction(map,key);
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	
	setNode(newNode,key,value);
	
	if(map->arr[index] == NULL){
		map->arr[index] = newNode;
	}
	else{
		newNode->next =map->arr[index];
		map->arr[index] = newNode;
	}
}
void printHashMap(struct hashMap* map){
	struct node *tmp;
	for(int i=0;i<map->capacity;i++){
		tmp = map->arr[i];
		while(tmp!=NULL){
			printf("map array[%d] value is %s\n",i,tmp->value);
			tmp=tmp->next;
		}
		
	}
}
char* searchHashMap(struct hashMap* map, char* key){

	int index=0;

	
	index=hashfunction(map,key);
	//printf("index is %d, 0x%x\n",index,map->arr[index]);
	struct node *lNode = map->arr[index];

	while(lNode != NULL){
		if(!strcmp(lNode->key,key))
			return lNode->value;
		else
			lNode=lNode->next;
	}
	
	//printf("%s\n","12345");
	return errMsg;

}
bool deleteKey(struct hashMap* map, char* key){
	struct node *pNode;
	
	int index = hashfunction(map,key);
	struct node *lNode = map->arr[index];
	
	while( lNode != NULL ){
		if(!strcmp(lNode->key,key)){
			//head node
			if(lNode == map->arr[index]){	
				map->arr[index]=lNode->next;
			}
			//middle or last node
			else{
				pNode->next=lNode->next;
			}
			free(lNode);
			return true;
		}else{
			pNode=lNode;
			lNode=lNode->next;
		}
	}
	return false;

	
}
void main(){
	
	struct hashMap* map = (struct hashMap*)malloc(sizeof(struct hashMap));
	initHashMap(map);
	
	insert(map,"apple","Leo");
	insert(map,"orange","Sare");
	insert(map,"pear","Sash");
	insert(map,"grape","Bob");
	insert(map,"pinapple","Jenny");
	insert(map,"rediron","Bonny");
	insert(map,"yellowcolor","Sunny");
	insert(map,"Greenshirt","Chris");
	insert(map,"skyline","Rob");
	insert(map,"whitebig","Kenny");
	
	printHashMap(map);
	
	printf("%s\n",searchHashMap(map,"whitebig"));
	printf("%s\n",searchHashMap(map,"pear"));
	printf("%s\n",searchHashMap(map,"yellowcolor"));
	//printf("%s\n",searchHashMap(map,"abcd"));
	
	deleteKey(map,"whitebig");
	printf("%s\n",searchHashMap(map,"whitebig"));
	
	printHashMap(map);
	

}
