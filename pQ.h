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
	PQItem* pQueue;//pQueue //kolejka realizowana w postaci stogu(kopca) //to b�dzie jako tablica o zadanej maksymalnej wielko�ci, wi�c musimy pamieta� rozmiar maksymalny tablicy jak rozmiar ca�kowity kolejki prorytetowej
	int PQSize; // rozmiar kolejki priorytetiwej
	int PQCurrSize;// ilosc element�w w kolejce // to te� jednoczenie indeks elementu do tablicy, gdzie wstawiany nowy element (wstawiamy o ile jest mniejsze od ilo�ci tablicy) po wstawieniu trzeba uaktualni� kpiec od do�u do g�ry
} PQueue;

//�ci�gamy zawsze element 0, ostatni przerzucamy na 0 i uaktualniamy stog od g�ry do do�u, zmniejszaj�c PQCurrSize o 1, a� do tego a� zostanie 1
PQueue* PQInit( int nSize ); // ma stowrzy� kolejke, tworzy strukture pQueue dynamicznie, dla pola pQueue przydziela pami�� o rozmiarze int, ustawia PQSize i PQCurrSize na 0
int PQisEmpty( PQueue* q); //zwraca warto�� 0 lub 1, w przypadku gdy klejka jest pusta to 1, jak  jest to 0 
void PQEnqueue( PQueue* q, int nKey, int nPrior ); //wk�ada do kolejki proiorytetowej, o kluczu i priorytecie jak podane
int PQDequeue( PQueue* q ); //wyci�ga z kolejki 1 element kt�ry ma najwy�sczy lub najmniejszy priorytet, my zrobimy �e na najwy�szy priorytet!
void PQClearQueue( PQueue* q ); // ma wyczy�ci� kolejk�, ca�a zostaje, tylko jest wyczyszczona
void PQRelease( PQueue** q ); //ca�kowicie usuwa kolejk� zwraca w parametrze we/wy NULLA, po zwolnieniu dynamicznej tablicy i ca�ej struktrury te� zwalniamy, wr�cimy do startu, �e mamy wska�nik, ale brak kolejki
void PQPrint( PQueue* q );//drukawnie kolejki/ mo�e by� na warunkowej kompilacji , inorder drukowa�(nie wiem co to znaczy xd), stog traktujemy jak drzwo binarne, tak to drukujemy
void DecreaseKey( PQueue* q, int nKey, int nPrior ); //(nPrior < Item.nPrior) je�li parametr nie jest mniejszy od aktualnego tego co ma w kluczu to nic nie robie, je�li jest to co� zmieniamu i uaktualniam
void IncreaseKey( PQueue* q, int nKey, int nPrior ); //(nPrior > Item.nPrior) je�li nPrior nie jest silnie wi�kszy od tego item npror to nic nie robi�

#endif