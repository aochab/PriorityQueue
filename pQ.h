#pragma once
#ifndef _QUEUE_INCLUDE_
#define _QUEUE_INCLUDE_

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int nKey;
	int nPrior;
} PQItem;

typedef struct
{
	PQItem* pQueue;
	int PQSize; 
	int PQCurrSize;
} PQueue;


PQueue* PQInit( int nSize ); 
int PQisEmpty( PQueue* q); 
void PQEnqueue( PQueue* q, int nKey, int nPrior ); 
int PQDequeue( PQueue* q ); 
void PQClearQueue( PQueue* q ); 
void PQRelease( PQueue** q ); 
void PQPrint( PQueue* q );
void DecreaseKey( PQueue* q, int nKey, int nPrior ); 
void IncreaseKey( PQueue* q, int nKey, int nPrior ); 

#endif
