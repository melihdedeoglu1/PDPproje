#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

struct CANLI{
	char* tur;
	int sayi;
	char* (*gorunum)(struct CANLI*);
	void (*yoket)(struct CANLI*);
	char* (*turget)(struct CANLI*);	
};
typedef struct CANLI* Canli;

Canli CanliOlustur(char*,int);
void CanliYokEt(const Canli);

#endif





