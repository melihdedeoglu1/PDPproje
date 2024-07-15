#ifndef SINEK_H
#define SINEK_H

#include "stdio.h"
#include "stdlib.h"
#include "Bocek.h"

struct SINEK{
	Bocek super;
	char* (*gorunum)(struct CANLI*);
	void (*yoket)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek SinekOlustur(char*,int);
char* SinekGorunum(const Canli) ;
void SinekYokEt(const Sinek);

#endif