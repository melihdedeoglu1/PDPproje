#ifndef PIRE_H
#define PIRE_H

#include "stdio.h"
#include "stdlib.h"
#include "Bocek.h"

struct PIRE{
	Bocek super;
	char* (*gorunum)(struct CANLI*);
	void (*yoket)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire PireOlustur(char*,int);
char* PireGorunum(const Canli) ;
void PireYokEt(const Pire);

#endif