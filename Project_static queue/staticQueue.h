#ifndef _staticQueue_H
#define _staticQueue_H

typedef struct sQueue
{
	int e, v, hossz;
	int* queue;
}sQueue;

sQueue* Create(int);

void Destroy(sQueue*);

void Push(sQueue*,int);

int Get(sQueue*);

void Pop(sQueue*);

void Print(sQueue*);

int isEmpty(sQueue*);

int Overload(sQueue*);

#endif