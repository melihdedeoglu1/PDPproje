#ifndef BOCEK_H
#define BOCEK_H

#include "stdio.h"
#include "stdlib.h"
#include "Canli.h"

struct BOCEK{
	Canli super;
	char* (*gorunum)(struct CANLI*);
	void (*yoket)(struct BOCEK*);
};
typedef struct BOCEK* Bocek;

Bocek BocekOlustur(char*,int);
char* BocekGorunum(const Canli) ;
void BocekYokEt(const Bocek);

#endif