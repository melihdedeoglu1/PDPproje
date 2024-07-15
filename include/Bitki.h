#ifndef BITKI_H
#define BITKI_H

#include "stdio.h"
#include "stdlib.h"
#include "Canli.h"

struct BITKI{
	Canli super;
	char* (*gorunum)(struct CANLI*);
	void (*yoket)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(char*,int);
char* BitkiGorunum(const Canli) ;
void BitkiYokEt(const Bitki);

#endif