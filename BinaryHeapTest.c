#include <stdio.h>
#include <stdlib.h>

struct HeapStruct{
	int Capacity;
	int Size;
	ElementType *Elements;
};
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	
	H = (PriorityQueue)malloc(sizeof(struct Heap));
	if(H == NULL) FatalError("Out Of Memory");
	H->Elements = (ElementType*)malloc(sizeof(ElementType)*(MaxElements));
	
	if( !H->Elements) FatalError("Out Of Memory");
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MIN_ELEMENT;
}

int Insert(ElementType X, PriorityQueue H)
{
	int i;
	
	if(IsFull(H)){
		Error("Priority Queue is Full");
		return;
	}
	
	H->Size++;
	for(i = H->Size; H->Elements[i/2] > X; i /=2){
		H->Elements[i] = H->Elements[i/2];
	}
	H->Element[i] = X;
}
