#include "staticQueue.h"
#include <iostream>
using namespace std;

sQueue* Create(int n)
{
	sQueue* Q = new sQueue;
	Q->v = 0;
	Q->e = 0;
	Q->hossz = n;
	Q->queue = new int[Q->hossz];
	return Q;
}

void Destroy(sQueue* Q)
{
	delete[]Q->queue;
	delete Q;
}

void Push(sQueue* Q,int ertek)
{
	if (Q->v == Q->hossz)
	{
		cout << "A varakozasi lista megtelt!" << endl;
		return;
	}
	else
	{
		Q->queue[Q->v] = ertek;
		Q->v++;
	}
}

int Get(sQueue* Q)
{
	if (Q->e == Q->v)
	{
		return -1;
	}
	else
	{
		return Q->queue[Q->e];
	}
}

void Pop(sQueue* Q)
{
	if (Q->e == Q->v)
	{
		cout << "A varakozasi lista ures!" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < Q->v-1; i++)
		{
			Q->queue[i] = Q->queue[i + 1];
		}
	}
	if (Q->v < Q->hossz)
	{
		Q->queue[Q->v] = 0;
	}
	Q->v--;
}

void Print(sQueue* Q)
{
	if (Q->e == Q->v)
	{
		cout << "A varakozasi lista ures!" << endl;
	}
	else
	{
		for (int i = Q->e; i < Q->v; i++)
		{
			cout << Q->queue[i] << " ";
		}
		cout << endl;
	}
}

int isEmpty(sQueue* Q)
{
	if (Q->e == Q->v)
	{
		return 1;
	}
	return 0;
}

int Overload(sQueue* Q)
{
	if (Q->v > Q->hossz)
	{
		return 1;
	}
	return 0;
}