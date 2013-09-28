/*Description:common  stack
*Author: zhanghongyu
*Aime: 28/09/2013
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct{
	void *elems;
	int elemsize;
	int loglength;
	int alloclength;
}stack;

void StackNew(stack *s, int elemsize);
void StackDispose(stack *s);
void StackPush(stack *s, void *elemAddr);
void StackPop(stack *s, void *elemAddr);

void StackNew(stack *s, int elemsize){
	s->loglength = 0;
	s->elemsize = elemsize;
	s->alloclength = 4;
	s->elems = malloc(4*elemsize);
//	assert(s->elems != NULL);
}

void StackDispose(stack *s){
	free(s->elems);
}

static void StackGrow(stack *s){
	s->alloclength *= 2;
	s->elems = realloc(s->elems, s->alloclength * s->elemsize);
}

void StackPush(stack *s, void *elemAddr){
	if (s->loglength == s->alloclength){
	StackGrow(s);
	}
	
	void *target = (char*)s->elems + s->loglength * s->elemsize;
	memcpy(target, elemAddr, s->elemsize);
	s->loglength++;
}

void StackPop(stack *s, void *elemAddr){
	void *source = (char*)s->elems + (s->loglength - 1) * s->elemsize;
	memcpy(elemAddr, source, s->elemsize);
	s->loglength--;
}

int main (){
	char* a[] = {"asd", "sdsdf", "gdf", "gdfg", "sdfg"};
	for (int i = 0; i < 5; i++){
		cout << a[i] <<"\t";
	}
	
	stack s;
	StackNew(&s, sizeof(char*));
	for (int j = 0; j < 5; j++ ){
		StackPush(&s, a+j);
	}
	char* p[5];
	StackPop(&s, p);
	StackPop(&s, p+1);
	StackPop(&s, p+2);
	StackPop(&s, p+3);
	StackPop(&s, p+4);
	for (int k = 0; k <5; k++){
		cout << p[k] <<"\t" ;
	}
}
