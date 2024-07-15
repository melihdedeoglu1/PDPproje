#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "stdlib.h"

struct DOSYA{
	void (*bilgi)(const char*,int*,int* );
	void (*adet)(const char*,int,int,int*,int*,int*,int*);
	void (*yoket)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya DosyaOlustur();
void DosyaYokEt(const Dosya);
void dosyaBilgiAl(const char*,int*,int* );
void adetBilgiAl(const char*,int,int,int*,int*,int*,int*);

#endif