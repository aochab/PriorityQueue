#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "pQ.h"

#define SIZE 11

using namespace std;

void input( PQueue* q, int nSize ); //insert random items

int main()
{
	srand( (unsigned int)time( NULL ) );
	PQueue* q = PQInit( SIZE );

	//Test functions
	input( q, SIZE - 1 );

	printf( "Queue:\n" );
	PQPrint( q );
	printf( "\n\n" );

	printf("Dequeue: %d\n",PQDequeue( q ));

	PQPrint( q );
	printf( "\n\n" );

	printf( "Two enqueue\n" );
	input( q, 2 );

	PQPrint( q );
	printf( "\n\n" );

	printf( "Dequeue: %d\n", PQDequeue( q ) );

	PQPrint( q );
	printf( "\n\n" );

	printf( "Two enqueue\n" );
	input( q, 2 );

	PQPrint( q );
	printf( "\n\nClear\n\n" );

	PQClearQueue( q );

	printf( "Dequeue: %d\n", PQDequeue( q ) );

	PQPrint( q );
	printf( "\n\n" );

	printf( "Three enqueue\n" );
	input( q, 3 );

	PQPrint( q );
	printf( "\n\n" );

	PQRelease( &q );

    return 0;
}

//==================================================================================
void input( PQueue* q, int nSize )
{
	for( int i = 0; i < nSize; i++ )
	{
		int nKey = rand() % 40 + 1;
		int nPrior = rand() % 15 + 1;
		PQEnqueue( q, nKey, nPrior );
		printf( "%d. %d\tprior:%d\n", i, nKey, nPrior );
	}
}
